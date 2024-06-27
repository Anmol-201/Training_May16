#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 6009
#define MAXLINE 1024
#define MAXCLIENTS 100

typedef struct {
    char query[100];
    char response[100];
} ChatBotDB;

typedef struct {
    int sockfd;
    struct sockaddr_in clientaddr;
} ClientInfo;

pthread_mutex_t lock;
ChatBotDB database[MAXCLIENTS];
int dbSize = 0;

void log_message(const char *level, const char *message) {
    printf("[%s] %s\n", level, message);
}

void processQuery(char *query, char *response) {
    for (int i = 0; i < dbSize; i++) {
        if (strcasecmp(query, database[i].query) == 0) {
            strcpy(response, database[i].response);
            return;
        }
    }
    strcpy(response, "I'm sorry, I don't understand your query.");
}

void loadDatabase() {
    FILE *file = fopen("database.txt", "r");
    if (!file) {
        log_message("FATAL", "Failed to open database file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s %[^\n]", database[dbSize].query, database[dbSize].response) != EOF) {
        dbSize++;
    }

    fclose(file);
    log_message("INFO", "Database loaded successfully");
}

void* handleClient(void *arg) {
    ClientInfo clientInfo = *(ClientInfo *)arg;
    int sockfd = clientInfo.sockfd;
    struct sockaddr_in clientaddr = clientInfo.clientaddr;
    char buffer[MAXLINE];
    char response[MAXLINE];
    char employeeID[100];
    char employeeDetails[MAXLINE];
    int validEmployee = 0;

    pthread_detach(pthread_self());
    free(arg);  // Free the allocated memory for ClientInfo

    // Ask for employee ID and validate
    write(sockfd, "Enter your employee ID: ", strlen("Enter your employee ID: "));
    int n = read(sockfd, employeeID, sizeof(employeeID));
    if (n <= 0) {
        close(sockfd);
        log_message("INFO", "Client disconnected during employee ID input");
        return NULL;
    }
    employeeID[strcspn(employeeID, "\n")] = 0;  // Remove newline character
    log_message("DEBUG", employeeID);  // Log the received employee ID

    // Dummy validation of employee ID
    if (strcmp(employeeID, "12345") == 0) {
        validEmployee = 1;
        write(sockfd, "Employee ID validated. How can I help you?\n", strlen("Employee ID validated. How can I help you?\n"));
        log_message("INFO", "Employee ID validated.");
    } else {
        write(sockfd, "Invalid ID. Disconnecting.\n", strlen("Invalid ID. Disconnecting.\n"));
        log_message("INFO", "Invalid employee ID. Disconnecting client.");
        close(sockfd);  // Close the connection
        return NULL;
    }

    while (1) {
        memset(buffer, 0, MAXLINE);
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            close(sockfd);
            log_message("INFO", "Client disconnected");
            return NULL;
        }

        buffer[n] = '\0';
        log_message("DEBUG", buffer);

        if (strcasecmp(buffer, "bye") == 0) {
            write(sockfd, "Goodbye!\n", strlen("Goodbye!\n"));
            close(sockfd);
            log_message("INFO", "Client disconnected");
            return NULL;
        }

        processQuery(buffer, response);
        write(sockfd, response, strlen(response));
        log_message("INFO", "Response sent to client");
    }
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    socklen_t len;

    loadDatabase();

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        log_message("FATAL", "Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        log_message("FATAL", "Bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    if (listen(sockfd, 5) == -1) {
        log_message("FATAL", "Listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    log_message("INFO", "Server listening on port 8080");

    while (1) {
        len = sizeof(cliaddr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) == -1) {
            log_message("WARNING", "Accept failed");
            continue;
        }

        ClientInfo *clientInfo = malloc(sizeof(ClientInfo));  // Allocate memory for ClientInfo
        if (clientInfo == NULL) {
            log_message("FATAL", "Memory allocation failed");
            close(newsockfd);
            continue;
        }
        clientInfo->sockfd = newsockfd;
        clientInfo->clientaddr = cliaddr;

        pthread_t tid;
        pthread_create(&tid, NULL, handleClient, (void *)clientInfo);
    }

    close(sockfd);
    return 0;
}


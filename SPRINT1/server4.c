#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 6969
#define MAXLINE 1024
#define MAXCLIENTS 100
#define MAXEMPLOYEES 100

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
char employeeIDs[MAXEMPLOYEES][20];
int dbSize = 0;
int empSize = 0;

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

void loadEmployeeIDs() {
    FILE *file = fopen("employees.txt", "r");
    if (!file) {
        log_message("FATAL", "Failed to open employee IDs file");
        exit(EXIT_FAILURE);
    }

    while (fscanf(file, "%s", employeeIDs[empSize]) != EOF) {
        empSize++;
    }

    fclose(file);
    log_message("INFO", "Employee IDs loaded successfully");
}

int validateEmployeeID(char *employeeID) {
    for (int i = 0; i < empSize; i++) {
        if (strcmp(employeeID, employeeIDs[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

void handleClient(void *arg) {
    ClientInfo clientInfo = *(ClientInfo *)arg;
    int sockfd = clientInfo.sockfd;
    char buffer[MAXLINE];
    char response[MAXLINE];
    char employeeID[100];
    char message[MAXLINE * 2];  // Buffer to hold the validation message and queries
    int validEmployee = 0;

    pthread_mutex_unlock(&lock);

    // Ask for employee ID and validate
    write(sockfd, "Enter your employee ID: ", strlen("Enter your employee ID: "));
    memset(employeeID, 0, sizeof(employeeID));
    int n = read(sockfd, employeeID, sizeof(employeeID));
    if (n <= 0) {
        close(sockfd);
        log_message("INFO", "Client disconnected during employee ID input");
        return;
    }
    employeeID[strcspn(employeeID, "\n")] = 0;  // Remove newline character
    log_message("DEBUG", employeeID);  // Log the received employee ID

    // Validate employee ID
    if (validateEmployeeID(employeeID)) {
        validEmployee = 1;

        // Prepare validation message along with some database queries
        snprintf(message, sizeof(message), "Employee ID validated. Here are some queries you can ask:\n");
        
        for (int i = 0; i < dbSize && i < 5; i++) {  // Sending first 5 queries as an example
            char queryMessage[MAXLINE];
            snprintf(queryMessage, sizeof(queryMessage), "%d. %s\n", i + 1, database[i].query);
            strncat(message, queryMessage, sizeof(message) - strlen(message) - 1);
        }
        strncat(message, "How can I help you?\n", sizeof(message) - strlen(message) - 1);
        
        write(sockfd, message, strlen(message));
        log_message("INFO", "Employee ID validated and queries sent.");
    } else {
        write(sockfd, "Invalid ID. Disconnecting...\n", strlen("Invalid ID. Disconnecting...\n"));
        close(sockfd);  // Close the socket on invalid ID
        log_message("INFO", "Client disconnected due to invalid employee ID");
        return;
    }

    while (1) {
        memset(buffer, 0, MAXLINE);
        n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            close(sockfd);
            log_message("INFO", "Client disconnected");
            return;
        }

        buffer[n] = '\0';
        log_message("DEBUG", buffer);

        if (strcasecmp(buffer, "bye") == 0) {
            write(sockfd, "Goodbye!\n", strlen("Goodbye!\n"));
            close(sockfd);
            log_message("INFO", "Client disconnected");
            return;
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
    loadEmployeeIDs();

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

        pthread_mutex_lock(&lock);
        ClientInfo clientInfo = {newsockfd, cliaddr};
        pthread_t tid;
        pthread_create(&tid, NULL, (void *)handleClient, (void *)&clientInfo);
    }

    close(sockfd);
    return 0;
}


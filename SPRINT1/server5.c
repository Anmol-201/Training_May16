#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <arpa/inet.h>

#define PORT 6009
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
char employeePasswords[MAXEMPLOYEES][20];
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

    while (fscanf(file, "%s %s", employeeIDs[empSize], employeePasswords[empSize]) != EOF) {
        empSize++;
    }

    fclose(file);
    log_message("INFO", "Employee IDs and passwords loaded successfully");
}

int validateEmployee(char *employeeID, char *password) {
    for (int i = 0; i < empSize; i++) {
        if (strcmp(employeeID, employeeIDs[i]) == 0) {
            if (strcmp(password, employeePasswords[i]) == 0) {
                return 1;
            } else {
                return -1; // Invalid password
            }
        }
    }
    return 0; // Employee ID not found
}

void addNewEmployee(char *employeeID, char *password) {
    FILE *file = fopen("employees.txt", "a");
    if (!file) {
        log_message("FATAL", "Failed to open employee IDs file for appending");
        return;
    }
    fprintf(file, "%s %s\n", employeeID, password);
    fclose(file);

    // Update the in-memory structure as well
    strcpy(employeeIDs[empSize], employeeID);
    strcpy(employeePasswords[empSize], password);
    empSize++;
    log_message("INFO", "New employee added successfully");
}

void sendQueries(int sockfd) {
    char message[MAXLINE * 2];
    snprintf(message, sizeof(message), "Here are some queries you can ask:\n");
    
    for (int i = 0; i < dbSize && i < 5; i++) {  // Sending first 5 queries as an example
        char queryMessage[MAXLINE];
        snprintf(queryMessage, sizeof(queryMessage), "%d. %s\n", i + 1, database[i].query);
        strncat(message, queryMessage, sizeof(message) - strlen(message) - 1);
    }
    strncat(message, "How can I help you?\n", sizeof(message) - strlen(message) - 1);
    write(sockfd, message, strlen(message));
}

void handleClient(void *arg) {
    ClientInfo clientInfo = *(ClientInfo *)arg;
    int sockfd = clientInfo.sockfd;
    char buffer[MAXLINE];
    char response[MAXLINE];
    char employeeID[100], password[100];
    int validEmployee = 0;

    pthread_mutex_unlock(&lock);

    // Ask for employee ID and password
    write(sockfd, "Enter your employee ID: ", strlen("Enter your employee ID: "));
    memset(employeeID, 0, sizeof(employeeID));
    int n = read(sockfd, employeeID, sizeof(employeeID));
    if (n <= 0) {
        close(sockfd);
        log_message("INFO", "Client disconnected during employee ID input");
        return;
    }
    employeeID[strcspn(employeeID, "\n")] = 0;  // Remove newline character

    write(sockfd, "Enter your password: ", strlen("Enter your password: "));
    memset(password, 0, sizeof(password));
    n = read(sockfd, password, sizeof(password));
    if (n <= 0) {
        close(sockfd);
        log_message("INFO", "Client disconnected during password input");
        return;
    }
    password[strcspn(password, "\n")] = 0;  // Remove newline character

    // Validate employee ID and password
    int validationStatus = validateEmployee(employeeID, password);
    if (validationStatus == 1) {
        validEmployee = 1;
        write(sockfd, "Employee ID and password validated.\n", strlen("Employee ID and password validated.\n"));
        log_message("INFO", "Employee ID and password validated.");
        sendQueries(sockfd);
    } else if (validationStatus == -1) {
        write(sockfd, "Invalid password. Disconnecting...\n", strlen("Invalid password. Disconnecting...\n"));
        close(sockfd);
        log_message("INFO", "Client disconnected due to invalid password");
        return;
    } else {
        write(sockfd, "Invalid ID. Do you want to add a new employee? (yes/no): ", strlen("Invalid ID. Do you want to add a new employee? (yes/no): "));
        memset(buffer, 0, sizeof(buffer));
        n = read(sockfd, buffer, sizeof(buffer));
        buffer[n] = '\0';
        if (strcasecmp(buffer, "yes\n") == 0) {
            write(sockfd, "Enter new employee ID: ", strlen("Enter new employee ID: "));
            memset(employeeID, 0, sizeof(employeeID));
            n = read(sockfd, employeeID, sizeof(employeeID));
            employeeID[strcspn(employeeID, "\n")] = 0;  // Remove newline character

            write(sockfd, "Enter new password: ", strlen("Enter new password: "));
            memset(password, 0, sizeof(password));
            n = read(sockfd, password, sizeof(password));
            password[strcspn(password, "\n")] = 0;  // Remove newline character

            addNewEmployee(employeeID, password);
            write(sockfd, "New employee added successfully.\n", strlen("New employee added successfully.\n"));
            sendQueries(sockfd);
        } else {
            write(sockfd, "Disconnecting...\n", strlen("Disconnecting...\n"));
            close(sockfd);
            log_message("INFO", "Client disconnected due to invalid employee credentials");
            return;
        }
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
        if (strcasecmp(response, "I'm sorry, I don't understand your query.") == 0) {
            write(sockfd, response, strlen(response));
            sendQueries(sockfd);
        } else {
            write(sockfd, response, strlen(response));
        }
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

    log_message("INFO", "Server listening on port 6009");

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


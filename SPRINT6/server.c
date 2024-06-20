#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

typedef struct {
    char query[100];
    char response[100];
} ChatBotDB;

ChatBotDB database[] = {
    {"hello", "Hi there! How can I assist you with college hiring?"},
    {"application process", "The application process involves submitting your resume and completing an interview."},
    {"eligibility criteria", "Freshers with a minimum of 70% aggregate are eligible to apply."},
    {"contact information", "You can reach us at hr@collegehire.com."},
    {"bye", "Goodbye! Have a great day!"}
};

void processQuery(char *query, char *response) {
    for (int i = 0; i < sizeof(database)/sizeof(database[0]); i++) {
        if (strcasecmp(query, database[i].query) == 0) {
            strcpy(response, database[i].response);
            return;
        }
    }
    strcpy(response, "I'm sorry, I don't understand your query.");
}

int main() {
    int sockfd, newsockfd;
    struct sockaddr_in servaddr, cliaddr;
    char buffer[MAXLINE];
    char response[MAXLINE];
    socklen_t len;

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = INADDR_ANY;
    servaddr.sin_port = htons(PORT);

    // Binding the socket with the server address
    if (bind(sockfd, (const struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("bind failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Start listening for incoming connections
    if (listen(sockfd, 5) == -1) {
        perror("listen failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d\n", PORT);

    while (1) {
        len = sizeof(cliaddr);
        if ((newsockfd = accept(sockfd, (struct sockaddr *)&cliaddr, &len)) == -1) {
            perror("accept failed");
            exit(EXIT_FAILURE);
        }

        memset(buffer, 0, MAXLINE);
        read(newsockfd, buffer, sizeof(buffer));

        printf("Received query: %s\n", buffer);

        processQuery(buffer, response);

        write(newsockfd, response, strlen(response) + 1);

        close(newsockfd);
    }

    close(sockfd);
    return 0;
}


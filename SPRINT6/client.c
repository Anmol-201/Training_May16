#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAXLINE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];
    char query[MAXLINE];

    // Creating socket file descriptor
    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    // Filling server information
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    // Connect to server
    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("connect failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    while (1) {
        printf("Enter your query: ");
        fgets(query, MAXLINE, stdin);
        query[strcspn(query, "\n")] = 0;  // Remove newline character

        write(sockfd, query, strlen(query) + 1);

        if (strcasecmp(query, "bye") == 0) {
            break;
        }

        memset(buffer, 0, MAXLINE);
        read(sockfd, buffer, sizeof(buffer));
        printf("Response from server: %s\n", buffer);
    }

    close(sockfd);
    return 0;
}


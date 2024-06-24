
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <arpa/inet.h>

#define PORT 2001
#define MAXLINE 1024

int main() {
    int sockfd;
    struct sockaddr_in servaddr;
    char buffer[MAXLINE];

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1) {
        perror("Socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = inet_addr("127.0.0.1");  // Replace with your server IP address
    servaddr.sin_port = htons(PORT);

    if (connect(sockfd, (struct sockaddr *)&servaddr, sizeof(servaddr)) == -1) {
        perror("Connection failed");
        close(sockfd);
        exit(EXIT_FAILURE);
    }

    // Interaction loop
    while (1) {
        memset(buffer, 0, MAXLINE);
        int n = read(sockfd, buffer, sizeof(buffer));
        if (n <= 0) {
            printf("Server disconnected\n");
            break;
        }

        printf("Server: %s", buffer);

        // Check for server asking for details
        if (strstr(buffer, "Please enter your details\n") != NULL) {
            // Provide details as needed
            fgets(buffer, MAXLINE, stdin);
            write(sockfd, buffer, strlen(buffer));
        } else if (strstr(buffer, "Enter your employee Password\n") != NULL) {
            // Prompt for password
            printf("\nPassword: ");
            fgets(buffer, MAXLINE, stdin);
            write(sockfd, buffer, strlen(buffer));
        } else {
            // Normal chat interaction
            printf("\nYou: ");
            fgets(buffer, MAXLINE, stdin);
            write(sockfd, buffer, strlen(buffer));
        }
    }

    close(sockfd);
    return 0;
}



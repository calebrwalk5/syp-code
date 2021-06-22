#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <strings.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netdb.h>

#define PORT 8080
#define MAXLINE 1024

void receiveMessage(char *message);
void sendMessage(char message[]);
char message[100];

int main(void) {

  char message[MAXLINE];
  fgets(message, MAXLINE, stdin);
  sendMessage(message);

}

void receiveMessage(char *message) {

  int sockfd;
  char buffer[MAXLINE];
  printf("Message to send: ");
  char *hello = "Hello from client.";

  struct sockaddr_in servaddr;
  struct hostent *server;

  bzero((char *)&servaddr, sizeof(servaddr));

  if ((server = gethostbyname("hostname")) == NULL) {

    printf("Error, host name not valid\n");

  }

  if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0) {

    perror("Socket creation failed");
    exit(EXIT_FAILURE);

  }

  servaddr.sin_family = AF_INET;
  servaddr.sin_port = htons(PORT);

  bcopy((char *)server->h_addr_list[0], (char *)&servaddr.sin_addr.s_addr, server->h_length);

  int n, len;

  sendto(sockfd, (const char *)hello, strlen(hello), MSG_CONFIRM, (const struct sockaddr *) &servaddr, sizeof(servaddr));

  printf("Hello message sent.\n");

  n = recvfrom(sockfd, (char *)buffer, MAXLINE, MSG_WAITALL, (struct sockaddr *)&servaddr, &len);

  buffer[n] = '\0';
  printf("Server: %s\n", buffer);

  strncpy(message, buffer, strlen(buffer));

  close(sockfd);

  return;

}

void sendMessage(char message[]) {

  int sockfd;
  char buffer[MAXLINE];
  char *sendingMessage = message;
  struct sockaddr_in servaddr, cliaddr;

  // Creating socket file descriptor
  if ( (sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0 ) {
      perror("socket creation failed");
      exit(EXIT_FAILURE);
  }

  memset(&servaddr, 0, sizeof(servaddr));
  memset(&cliaddr, 0, sizeof(cliaddr));

  // Filling server information
  servaddr.sin_family    = AF_INET; // IPv4
  servaddr.sin_addr.s_addr = INADDR_ANY;
  servaddr.sin_port = htons(PORT);

  // Bind the socket with the server address
  if ( bind(sockfd, (const struct sockaddr *)&servaddr,
          sizeof(servaddr)) < 0 )
  {
      perror("bind failed");
      exit(EXIT_FAILURE);
  }

  int len, n;

  len = sizeof(cliaddr);  //len is value/resuslt

  n = recvfrom(sockfd, (char *)buffer, MAXLINE,
              MSG_WAITALL, ( struct sockaddr *) &cliaddr,
              &len);
  buffer[n] = '\0';
  printf("Client : %s\n", buffer);
  sendto(sockfd, (const char *)sendingMessage, strlen(sendingMessage),
      MSG_CONFIRM, (const struct sockaddr *) &cliaddr,
          len);
  printf("Message sent.\n");

  return;

}

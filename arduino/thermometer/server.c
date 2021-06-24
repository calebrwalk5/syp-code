#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>

#define PORT 8080
#define MAXLINE 1024

int main(int argc , char *argv[]) {
	int socket_desc , client_sock , c , read_size;
	struct sockaddr_in server , client;
	char client_message[MAXLINE];
	
	socket_desc = socket(AF_INET , SOCK_STREAM , 0);
	if (socket_desc == -1) {
		printf("socket failed");
	}
	printf("socket created\n");
	
	server.sin_family = AF_INET;
	server.sin_addr.s_addr = INADDR_ANY;
	server.sin_port = htons(PORT);


	if (bind(socket_desc,(struct sockaddr *) &server , sizeof(server)) < 0) {
		perror("bind failed");
		return 1;
	}
	printf("bind done\n");
	
    // listen for the client 
	listen(socket_desc , 3);
	
	printf("Waiting for incoming connections\n");
	c = sizeof(struct sockaddr_in);
	
	client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&c);
	if (client_sock < 0) {
		perror("accept failed");
		return 1;
	}
	printf("connetion accepted\n");
	
	// recieve message
	while( (read_size = recv(client_sock , client_message , MAXLINE , 0)) > 0 ) {
		write(client_sock , client_message , strlen(client_message));
	}
	
	if (read_size == 0) {
		printf("Client disconnected\n");
		fflush(stdout);
	}
	else if (read_size == -1) {
		perror("recv failed");
	}
	
	return 0;
}
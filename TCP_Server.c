#include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>

 #define PORT 5555

 void main(){

 void error(char *msg)
 /* ERROR HANDLING FUNCTION USING STANDARD C LIBRARY FUNCTIONS
    WILL BE CALLED IN THE EVENT OF AN ERROR, BIND FAILURE FOR
    EXAMPLE, AND TERMINATES THE PROGRAM, EXIT STATUS 1 */
 {
   perror(msg);
   exit(1);
 }

 int sockfd;
 // FILE DESCRIPTOR FOR STORING VALUES RETURNED BY SOCKET CALL AND ACCECPT CALL
struct sockaddr_in servAddr;
int i;
int NewSocket;
struct sockaddr_in newAddr;

socklen_t addr_size;
char buffer[1024];

sockfd = socket(PF_INET, SOCK_STREAM, 0); // SOCK_STREAM FOR TCP
if(sockfd < 0){
  error("Error opening socket.");
}

memset(&servAddr, '\0', sizeof(servAddr));
//#include <netinet/in.h>
servAddr.sin_family = AF_INET;     // ADDRESS FAMILY
servAddr.sin_port = htons(PORT);  // PORT IN NETWORK BYTE ORDER
servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // HOST ADDRESS LOOPBACK
// NEED TO BIND ADDRESS TO A SPECIFIC PORT FOR CLIENT TO LISTEN
i = bind(sockfd, (struct sockaddr*)&servAddr, sizeof(servAddr));
/*if(i < 0){
  error("Error Binding.");
}*/
listen(sockfd, 5); // THIS IS HOW MANY CLIENTS YOU CAN CONNECT TO AT ONCE
addr_size = sizeof(newAddr);
// CREATE A NEW SOCKET FOR NEW CLIENT CONNECTION REQUESTS
// NEW SOCKETS CAN BE CREATED AND ANY EXISTING ARE UNAFFECTED
NewSocket = accept(sockfd, (struct sockaddr*)&newAddr, &addr_size);
// CREATE A RESPONSE FOR THE CLIENTS
strcpy(buffer, "I can hear you!\0"); // TERMINATE WITH "\0" TO PREVENT ANY GARBAGE
                                    //  DATA FROM BEING TRANSMITTED
send(NewSocket, buffer, strlen(buffer), 0);
printf("\n");

}

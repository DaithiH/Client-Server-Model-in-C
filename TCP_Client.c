 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>
 #include <sys/socket.h>
 #include <sys/types.h>
 #include <netinet/in.h>
 #include <arpa/inet.h>     // TO USE htons(): Host To Network Short
                            // CONVERTS HOST BYTE ORDER TO NETWORK BYTE ORDER
                            // HOST BYTE IS LSB; NETWORK IS MSB
#define PORT 5555

void error(char *msg)
/* ERROR HANDLING FUNCTION USING STANDARD C LIBRARY FUNCTIONS
   WILL BE CALLED IN THE EVENT OF AN ERROR, BIND FAILURE FOR
   EXAMPLE, AND TERMINATES THE PROGRAM, EXIT STATUS 0*/
  {
    perror(msg);
    exit(0);
  }

 void main(){
   int clientSocket;
   int i;
   struct sockaddr_in servAddr;
   char buffer[1024];

   clientSocket = socket(AF_INET, SOCK_STREAM, 0);
                     /* (ADDRESS FAMILY, TYPE, PROTOCOL)
                         AF_INET is IPv4; AF_INET6 is IPv6
                         SOCK_STREAM used for TCP 2-way connection based stream
                         SOCK_DGRAM used for UDP Best Effort protocol
                         0 sets default protocol */
    if (clientSocket < 0){
      perror("Error Opening Socket!"); // ERROR MESSAGE IF SOCKET RETURNS NULL OR -1
    }

    memset(&servAddr, '\0', sizeof(servAddr));
    //#include <netinet/in.h>
    servAddr.sin_family = AF_INET;     // ADDRESS FAMILY
    servAddr.sin_port = htons(PORT);   // PORT IN NETWORK BYTE ORDER
    servAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // LOOPBACK ADDRESS FOR USING THE SAME MACHINE
                                                       // FOR CLIENT AND SERVER

    connect(clientSocket, (struct sockaddr*)&servAddr, sizeof(servAddr));
    if(connect < 0){
      error("Error Connecting!");
    }
    recv(clientSocket, buffer, 1024, 0);
    printf("Receiving: %s", buffer);
    printf("\n\n");
 }

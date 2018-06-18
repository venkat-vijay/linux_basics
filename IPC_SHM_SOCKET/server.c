// header files

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
 
int main(void)
{
	int listenfd = 0,connfd = 0;     // declared and initialized two socket identifiers 
//Details of struct sockaddr_in is available in man 7 ip.
	struct sockaddr_in serv_addr;    // Socket address structure
        char sendBuff[1025];             // Buffer to hold string
  	int numrv;  
 
/* First step in any socket program, is to create our socket using socket funtion.
We specify we're creating an IP socket(Using AF_INET), using reliable stream protocol type(SOCK_STREAM)
The zero as the third argument specifies to use default protocol of the stream type, which is TCP.
Refer man 2 socket for more information, on other possible types of Protocols and Socket types.
*/
 	listenfd = socket(AF_INET, SOCK_STREAM, 0);
	if(listenfd == -1){
		printf("Socket endpoint creation failed\n");
		exit(0);
	}
		
  	printf("socket retrieve success\n");
  
// here we are binding a port and address to the socket

/*
The memset() function fills the bytes of the memory(sizeof(serv_addr)) area pointed to by &serv_addr with the constant byte 0.
similarly for sendBuff
*/
  	memset(&serv_addr, '0', sizeof(serv_addr));
  	memset(sendBuff, '0', sizeof(sendBuff));
/*
Details of struct sockaddr_in is available in man 7 ip.

 struct sockaddr_in {
               sa_family_t    sin_family;  address family: AF_INET 
               in_port_t      sin_port;    port in network byte order 
               struct in_addr sin_addr;    internet address 
  	         };

            Internet address. 
           struct in_addr {
               uint32_t       s_addr;     address in network byte order 
           };

*/  

//sin_family is AF_INET for IP Socket    
  	serv_addr.sin_family = AF_INET;   
//The inet_addr() function converts the Internet  host  address  cp  from 
//IPv4  numbers-and-dots notation into binary data in network byte order.
 	serv_addr.sin_addr.s_addr = inet_addr("200.200.200.191"); 
// The htons() function converts the unsigned short integer hostshort from
//host byte order to network byte order.  	
	serv_addr.sin_port = htons(5000);    

/*
bind() assigns the address specified by addr to the  socket  referred to by the file descriptor sockfd
*/

  	bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));

/* For a client to connect to our socket (which is bound to our port and IPv4 address).
This tells the protocol stack that we are ready to accept connections (a maximum of 10 pending connections)
*/  
  	if(listen(listenfd, 10) == -1){
      		printf("Failed to listen\n");
      		return -1;
  	}
     
  
  	while(1)
    	{
/*
accept() is the final call made by servers to accept incoming client connections.
Before accept(), server socket must be created and bound with server IP and port, and listen must be called.
The accept() returns a socket descriptor for the client socket.

The call to accept will block until a client connection is available.
Now, we are not capturing any client information, thereby given second and third argument as
(struct sockaddr*)NULL and NULL..
Otherwise give appropriate arguments
*/
      		connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request
  		
      		strcpy(sendBuff, "HELLO THERE!,Message from server");
      		write(connfd, sendBuff, strlen(sendBuff));
 
	        close(connfd);    
      		sleep(1);
    	}
  	return 0;
}

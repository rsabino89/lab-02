/* A simple server in the internet domain using TCP
 * Answer the questions below in your writeup
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h> 
#include <sys/socket.h>
#include <netinet/in.h>

void error(const char *msg)
{
    perror(msg);
    exit(1);
}

int main(int argc, char *argv[])
{
    /* 1. What is argc and *argv[]?
     *argc is an integer that denotes how many arguments are entered on the command line when
     *the program is started. *argv[] is an array of pointers to arrays of char objects, where
     * The first element argv[0] is the name of the program executing and the following elements
     * are the parameters being supplied from the command line in order.
     */
    int sockfd, newsockfd, portno;
    /* 2. What is a UNIX file descriptor and file descriptor table?
     * A UNIX file descriptor is a process ID for a file or other input/output source like a
     * socket or pipe. A file descriptor table is a collection of file descriptors whose 
     * elements are pointers to file table entries maintained by the kernel. Each process
     * has its own file descriptor table.
     */
    socklen_t clilen;

    struct sockaddr_in serv_addr, cli_addr;
    /* 3. What is a struct? What's the structure of sockaddr_in?
     * A struct is a data structure which groups data elements under one name. sockaddr_in
     * contains a short, unsigned short, an in_addr struct, and a char.
     */
    
    int n;
    if (argc < 2) {
        fprintf(stderr,"ERROR, no port provided\n");
        exit(1);
    }
    
    sockfd = socket(AF_INET, SOCK_STREAM, 0);
    /* 4. What are the input parameters and return value of socket()
     *   the input parameters of socket() are in order: domain, type, and protocol.
     *   The first input for domain is an integer which specifies the communication domain.
     *   The second input is communication type, TCP or UDP. The last input is for the
     *   protocol value for IP. The return type of socket is an int for socket descriptor.
     */
    
    if (sockfd < 0) 
       error("ERROR opening socket");
    bzero((char *) &serv_addr, sizeof(serv_addr));
    portno = atoi(argv[1]);
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(portno);
    
    if (bind(sockfd, (struct sockaddr *) &serv_addr,
             sizeof(serv_addr)) < 0) 
             error("ERROR on binding");
    /* 5. What are the input parameters of bind() and listen()?
     * The input parameters of bind() are an int, a pointer to a sockaddr struct which contains 
     * the name to be bound to the socket, and the size of the address in bytes.
     */
    
    listen(sockfd,5);
    clilen = sizeof(cli_addr);
    
    while(1) {
        /* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *  Since this server is only intended to connect to one client, we use while(1) because
        *  only one connection is anticipated and the server is waiting on a connection request 
        *  from the client. If there were more connections to handle, it
        *  would only be able to handle one, so it would connect to the first request and 
        *  ignore the rest.
        */
        
	char buffer[256];
        newsockfd = accept(sockfd, 
                    (struct sockaddr *) &cli_addr, 
                    &clilen);
	/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * Fork creates a child process from a parent process, allowing for two separate
         * threads to execute in different address spaces simultaneously. It can be applied
         * here by adding a fork call (and checking that it is successful) in this loop.
         * This could be done with the following after instantiating pid child_pid:
         * if ((childpid = fork()) == 0) {
         *	//insert desired action ie send message
         * }
         */
        
	if (newsockfd < 0) 
             error("ERROR on accept");
	bzero(buffer,256);
        
	n = read(newsockfd,buffer,255);
        if (n < 0) 
            error("ERROR reading from socket");
        printf("Here is the message: %s\n",buffer);
        n = write(newsockfd,"I got your message",18);
        if (n < 0) 
            error("ERROR writing to socket");
        close(newsockfd);
    }
    close(sockfd);
    return 0; 
}
  
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 *  A system call is a way for a computer program to request service from the kernel of the OS.
 */

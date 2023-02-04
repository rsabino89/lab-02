# Lab 2
[Fork](https://docs.github.com/en/get-started/quickstart/fork-a-repo) this repo and clone it to your machine to get started!

## Team Members
- Raymond Sabino

## Lab Question Answers

Answer for Question 1: 
  Roughly 50% of the packets I attempted to send were never received and displayed on the UDP server. This is because UDP doesn't establish a session like TCP does. UDP has less redundancy checks to confirm the reception of a packet, so the packets were not resent.

Answer for Question 2:
  TCP still received and displayed all of the packets sent. However, about half of the time it took longer for this to happen. Due to the redundancy checks done by the TCP protocol, packets lost were resent despite half of them being lost.

Answer for Question 3:
  The speed of the TCP response became slower for about half of the characters sent. This is because the initial packet sent was lost but not resent until after it was finally successfully delivered, which probably took multiple retransmissions.

/* 1. What is argc and *argv[]?
     *argc is an integer that denotes how many arguments are entered on the command line when
     *the program is started. *argv[] is an array of pointers to arrays of char objects, where
     * The first element argv[0] is the name of the program executing and the following elements
     * are the parameters being supplied from the command line in order.
     */
/* 2. What is a UNIX file descriptor and file descriptor table?
     * A UNIX file descriptor is a process ID for a file or other input/output source like a
     * socket or pipe. A file descriptor table is a collection of file descriptors whose 
     * elements are pointers to file table entries maintained by the kernel. Each process
     * has its own file descriptor table.
     */
/* 3. What is a struct? What's the structure of sockaddr_in?
     * A struct is a data structure which groups data elements under one name. sockaddr_in
     * contains a short, unsigned short, an in_addr struct, and a char.
     */
/* 4. What are the input parameters and return value of socket()
     *   the input parameters of socket() are in order: domain, type, and protocol.
     *   The first input for domain is an integer which specifies the communication domain.
     *   The second input is communication type, TCP or UDP. The last input is for the
     *   protocol value for IP. The return type of socket is an int for socket descriptor.
     */
/* 5. What are the input parameters of bind() and listen()?
     * The input parameters of bind() are an int, a pointer to a sockaddr struct which contains 
     * the name to be bound to the socket, and the size of the address in bytes.
     */
/* 6.  Why use while(1)? Based on the code below, what problems might occur if there are multiple simultaneous connections to handle?
        *  Since this server is only intended to connect to one client, we use while(1) because
        *  only one connection is anticipated and the server is waiting on a connection request 
        *  from the client. If there were more connections to handle, it
        *  would only be able to handle one, so it would connect to the first request and 
        *  ignore the rest.
        */
/* 7. Research how the command fork() works. How can it be applied here to better handle multiple connections?
         * Fork creates a child process from a parent process, allowing for two separate
         * threads to execute in different address spaces simultaneously. It can be applied
         * here by adding a fork call (and checking that it is successful) in this loop.
         * This could be done with the following after instantiating pid child_pid:
         * if ((childpid = fork()) == 0) {
         *	//insert desired action ie send message
         * }
         */
/* This program makes several system calls such as 'bind', and 'listen.' What exactly is a system call?
 *  A system call is a way for a computer program to request service from the kernel of the OS.
 */

//Copyright (C) 2015  Corwin Hansen
#ifndef SOCKET_HEADER//Include protection
#define SOCKET_HEADER
#ifdef __FreeBSD__ || __NetBSD__ || __OpenBSD__ || __bsdi__ || __DragonFly__//If platform has Berkeley sockets
#define _BSD_SOCK_
#endif

#elif defined __unix__ || defined unix || defined __unix //if platform is unix but not BSD
#define _POSIX_SOCK_
#endif

#elif defined _WIN32 //if platform has winsock
#define _WIN_SOCK_
#endif


#ifdef _BSD_SOCK_ //Berkeley sockets code
//headers for Berkeley sockets
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h> //error handling
#include <unistd.h> //unix close function
#include <stdlib.h>//standard stuff
#include <stdio.h>
#define socerr() errno //return errno for error
#define socket int //socket data type is int
#endif 


#ifdef _POSIX_SOCK_ //Posix sockets code
//headers for Posix sockets
#include <sys/socket.h>
#include <netinet/in.h>
#include <sys/un.h>
#include <arpa/inet.h>
#include <netdb.h>
#include <errno.h> //error handling
#include <unistd.h> //unix close function
#include <stdlib.h>//standard stuff
#include <stdio.h>
#define socerr() errno //return errno for error
#define socket int //socket data type is int
#endif


#ifdef _WIN_SOCK_ //winsock code
//headers for winsock
#include <winsock.h>
#include <stdlib.h>//standard stuff
#include <stdio.h>
#define socerr() WSAGetLastError()//return WSAGetLastError function for error
#define close(SD) closesocket(SD) //run closesocket function
#define socket SOCKET
#endif


#endif
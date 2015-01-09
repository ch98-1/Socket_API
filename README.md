Socket_API
==========

Header file for cross platform socket API close to Berkeley sockets.   
This is a simple Berkeley sockets like API in c for platforms that may support other sockets API.  
Include the header file in a c project to use this API.  
  
Potable Sockets API
-------------------
  
### Macros
#### Support
**_SOCK_SUPPORT_**   Defined if this platform has supported socket API. 

**_BSD_SOCK_** Defined if using Berkeley sockets.

**_POSIX_SOCK_**  Defined if using Posix sockets.

**_WIN_SOCK_**   Defined if using Winsock.
    
### Functions
**socerr()**   Returns last error number. errno for UNIX and WSAGetLastError() for windows. Returns system specific error numbers.  
  
**close()**   Closes socket and release resources allocated to a socket. closesocket() for winsock.  
  
### Datatypes
  
**socket***   Datatype for a socket. Object like maceo.  

#ifndef SCOUT_H
#define SCOUT_H 

#include <sys/socket.h>
#include <sys/types.h>
#include <netdb.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <errno.h>
#include <unistd.h>


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#endif
struct addrinfo* translate_address(const char* argv[]);
int resolve_address(const char* argv[]);


// Custom Header Files
#include "../include/scout.h"



struct addrinfo* translate_address(const char* argv[]) {

  struct addrinfo filter;
  memset(&filter, 0, sizeof filter);
  filter.ai_flags = AI_ALL;
  filter.ai_socktype = SOCK_DGRAM;
  filter.ai_flags = AI_CANONNAME;

  struct addrinfo *response;
  if (getaddrinfo(argv[1], argv[2], &filter, &response)) {
    fprintf(stderr, "Failed to Resolve the hostname and port with error code: %d\n", errno);
    exit(EXIT_FAILURE);
  }

  return response;

}


int resolve_address(const char* argv[]) {
  struct addrinfo *response = translate_address(argv);
  
  printf("Resolving the Hostname...\n");

  struct addrinfo *address = response;
  
  while (address != NULL) {
    char host[INET6_ADDRSTRLEN];

    if (address->ai_family == AF_INET) {
      struct sockaddr_in *ipv4 = (struct sockaddr_in *) &address->ai_addr;
      inet_ntop(AF_INET, &(ipv4->sin_addr), host, INET6_ADDRSTRLEN);
    }
    else {
      struct sockaddr_in6 *ipv6 = (struct sockaddr_in6 *) &address->ai_addr;

      inet_ntop(AF_INET6, &(ipv6->sin6_addr), host, INET6_ADDRSTRLEN);
    }


    printf("Address is: %s\n", host);
    printf("Address Type is: %s\n", address->ai_family == AF_INET? "IPv4" : "IPv6");
    
    if (address->ai_canonname != NULL) {
      printf("CNAME is: %s\n\n", address->ai_canonname);
    } else {
      printf("\n\n");
    }
    
    address = address->ai_next;
  }

  freeaddrinfo(response);
  return 0;
}


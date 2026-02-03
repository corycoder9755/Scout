#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Give Custom Files 
#include "../include/scout.h"

void make_basic_cheks(int);


void make_basic_cheks(int argc) {
  if (argc < 3) {
    fprintf(stderr, "Usage[+] scout <hostname> <port>...\n");
    exit(EXIT_FAILURE);
  }
}

int main(int argc, const char *argv[])
{
  
  // Scout Project
  make_basic_cheks(argc);

  int result = resolve_address(argv);

  if (result != 0) {
      fprintf(stderr, "Resolution Failed with error code: %d\n", errno);
      return -1;
  }
  
  return 0;
}


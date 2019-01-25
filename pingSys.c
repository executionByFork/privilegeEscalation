#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int BUFFERSIZE = 512;

void main(int argc, char** argv) {
  char ipaddr[BUFFERSIZE];
  snprintf(ipaddr, BUFFERSIZE, "ping -c 4 %s", argv[1]);
  setuid(0);
  system(ipaddr);
}

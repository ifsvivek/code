#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define MAX_BUF 1024
int main() {
  int fd;
  char* myfifo = "/tmp/myfifo";
  char buf[MAX_BUF];
  fd = open(myfifo, O_RDWR);
  read(fd, buf, MAX_BUF);
  printf("Writer: %s\n", buf);
  close(fd);
  return 0;
}

/*
output:
Writer: Hello
*/
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
  int fd;
  char buf[1024];
  char* myfifo = "/tmp/myfifo";
  mkfifo(myfifo, 0666);
  printf("Run Reader Process to read the fifo file\n");
  fd = open(myfifo, O_WRONLY);
  write(fd, "Hello", sizeof("Hello"));
  close(fd);
  unlink(myfifo);
  return 0;
}

/*
output:
Run Reader Process to read the fifo file
*/
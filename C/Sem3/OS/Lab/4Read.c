#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#define MAX_BUF 1024
int main(){
    int fd;
    char *myfifo = "/tmp/myfifo";
    char buf[MAX_BUF];
    fd = open(myfifo, O_RDWR);
    read(fd, buf, MAX_ BUF);
    printf("writer:%s\n", buf);
    close(fd);
    return 0;
}
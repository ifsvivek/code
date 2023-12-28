#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
    pit_t pid;
    pid = fork();
    if(pid < 0){
        printf(“fork failed”);
        exit(0);
    }
    else if (pid == 0){
        printf(“child process”);
        execlp(“ls”,”ls”,”- l”, NULL);
    }
    else{
        Wait(NULL);
        printf(“Child Complete ”);
        exit(0);
    }
}
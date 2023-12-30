#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(){
    pid_t pid;

    pid = fork();

    if(pid < 0){
        printf("fork failed\n");
        exit(1);
    }
    else if (pid == 0){
        printf("child process\n");
        execlp("ls", "ls", "-l", NULL);
    }
    else{
        wait(NULL);
        printf("Child Complete\n");
        exit(0);
    }
}

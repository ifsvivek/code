#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
<<<<<<< HEAD
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
=======
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
>>>>>>> 387c2e8eb643ee0af8fbf29403fc9e25f2cdc64d

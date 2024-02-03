// Develop a c program to implement the Process system calls (fork (), exec(),
// wait(), create process,terminate process)

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  pid_t pid;

  pid = fork();

  if (pid < 0) {
    printf("fork failed\n");
    exit(1);
  } else if (pid == 0) {
    printf("child process\n");
    execlp("ls", "ls", "-l", NULL);
  } else {
    wait(NULL);
    printf("Child Complete\n");
    exit(0);
  }
}
// 3. Develop a C program to simulate producer-consumer problem using semaphores.
#include <stdio.h>
#include <stdlib.h>
int mutex = 1, full = 0, empty = 3, x = 0;

int wait(int s) {
    return (--s);
}
int signal(int s) {
    return (++s);
}
void producer() {
    mutex = wait(mutex);
    full = signal(full);
    empty = wait(empty);
    x++;
    printf("\nProducer produces the item%d", x);
    mutex = signal(mutex);
}
void consumer() {
    mutex = wait(mutex);
    full = wait(full);
    empty = signal(empty);
    printf("\nConsumer consumes item%d", x);
    x--;
    mutex = signal(mutex);
}
void main() {
    int n;
    printf("\n1.PRODUCER\n2.CONSUMER\n3.EXIT\n");
    while (1) {
        printf("\nENTER YOUR CHOICE\n");
        scanf("%d", &n);
        switch (n) {
        case 1:
            if ((mutex == 1) && (empty != 0))
                producer();
            else
                printf("BUFFER IS FULL");
            break;
        case 2:
            if ((mutex == 1) && (full != 0))
                consumer();
            else
                printf("BUFFER IS EMPTY");
            break;
        case 3:
            exit(0);
            break;
        }
    }
}

/*
output:
1.PRODUCER
2.CONSUMER
3.EXIT

ENTER YOUR CHOICE
1

producer produces the item1
ENTER YOUR CHOICE
1

producer produces the item2
ENTER YOUR CHOICE
2

consumer consumes item2
ENTER YOUR CHOICE
2

consumer consumes item1
ENTER YOUR CHOICE
2
BUFFER IS EMPTY
ENTER YOUR CHOICE
3
*/
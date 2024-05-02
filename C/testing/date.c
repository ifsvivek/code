#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_THREADS 128

char* randstring(size_t len) {
    static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char* random = NULL;

    if (len) {
        random = malloc(sizeof(char) * (len + 1));

        if (random) {
            for (size_t n = 0; n < len; n++) {
                int key = rand() % (int)(sizeof(charset) - 1);
                random[n] = charset[key];
            }

            random[len] = '\0';
        }
    }

    return random;
}

void* thread_function(void* thread_arg) {
    int* thread_id = (int*)thread_arg;
    int c = 1;

    while (1) {
        char HEE[11];

        for (int i = 0; i < 10; i++) {
            HEE[i] = '\0';
        }

        char HE[11];
        strcpy(HEE, randstring(10));
        HE[0] = 'H';
        HE[1] = 'E';
        HE[2] = 'L';
        HE[3] = 'L';
        HE[4] = 'O';
        HE[5] = 'W';
        HE[6] = 'O';
        HE[7] = 'R';
        HE[8] = 'L';
        HE[9] = 'D';
        HE[10] = '\0';
        if (HEE[0] == 'H' && HEE[1] == 'E' && HEE[2] == 'L' && HEE[3] == 'L' && HEE[4] == 'O' && HEE[5] == 'W' && HEE[6] == 'O' && HEE[7] == 'R' && HEE[8] == 'L' && HEE[9] == 'D') {
            printf("%c\n", HEE[0]);
        }
        c++;
    }
}

int main() {
    pthread_t threads[NUM_THREADS];
    int thread_ids[NUM_THREADS];

    srand((unsigned int)time(NULL));

    for (int i = 0; i < NUM_THREADS; i++) {
        thread_ids[i] = i;
        pthread_create(&threads[i], NULL, thread_function, (void*)&thread_ids[i]);
    }

    for (int i = 0; i < NUM_THREADS; i++) {
        pthread_join(threads[i], NULL);
    }

    return 0;
}
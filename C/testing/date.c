#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char *randstring(size_t len)
{

    static char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char *random = NULL;

    if (len)
    {
        random = malloc(sizeof(char) * (len + 1));

        if (random)
        {
            for (int n = 0; n < len; n++)
            {
                int key = rand() % (int)(sizeof(charset) - 1);
                random[n] = charset[key];
            }

            random[len] = '\0';
        }
    }

    return random;
}

int main()
{
    int c = 1;
    double time = 0.0;
    clock_t start = clock();

    while (2 < 3)
    {
        char HEE[10];

        for (int i = 0; i < 10; i++)
        {
            HEE[i] = NULL;
        }

        char HE[10];
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
        if (strcmp(HEE, HE))
        {
            printf("Success at %ith attempt", c);
            break;
        }
        c++;
    }
    clock_t end = clock();
    time += (double)(end - start);
    printf("Time Taken: %lf", time);

    return 0;
}
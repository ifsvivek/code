#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Calendar {
    char *name;
    char *description;
    int day;
};

typedef struct Calendar Cal;

Cal* create() {
    return (Cal*)malloc(7 * sizeof(Cal));
}

void read(Cal* days) {
    int dayIndex, flag;
    char temp[50];

    for (int i = 0; i < 7; i++) {
        days[i].name = NULL;
        days[i].day = -1;
        days[i].description = NULL;
    }

    do {
        printf("Enter the day Number: ");
        scanf("%d", &dayIndex);

        if (dayIndex < 0 || dayIndex > 6) {
            printf("Invalid Input\n");
        } else {
            days[dayIndex].day = dayIndex;
            printf("Enter the day name and description: ");
            scanf("%s", temp);
            days[dayIndex].name = strdup(temp);
            scanf("%s", temp);
            days[dayIndex].description = strdup(temp);
        }

        printf("Enter 1 for more activities, else 0: ");
        scanf("%d", &flag);
    } while (flag != 0);
}

void display(Cal* days) {
    printf("Day\t\tDay Number\t\tDescriptions\n");

    for (int i = 0; i < 7; i++) {
        if (days[i].day != -1) {
            printf("%s\t\t%d\t\t\t%s\n", days[i].name, days[i].day, days[i].description);
        }
    }
}

int main() {
    Cal* days = create();
    read(days);
    display(days);
    free(days);

    return 0;
}

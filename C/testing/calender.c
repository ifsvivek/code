#include <stdio.h>
#include <time.h>
#include <string.h>

int main() {
    int day, month, year;

    printf("Enter date (dd mm yyyy): ");
    scanf("%d %d %d", &day, &month, &year);

    // Validate the input
    if (day <= 0 || month <= 0 || month > 12 || year < 1583) {
        printf("Invalid date input.\n");
        return 1;
    }

    // Clear the input buffer to avoid any remaining characters
    while (getchar() != '\n');

    // Create a struct tm with the entered date
    struct tm date;
    memset(&date, 0, sizeof(struct tm));
    date.tm_mday = day;
    date.tm_mon = month - 1;
    date.tm_year = year - 1900;

    // Use mktime to convert the struct tm to a time_t value
    time_t t = mktime(&date);

    if (t == -1) {
        printf("Invalid date.\n");
        return 1;
    }

    // Use localtime to get the day of the week
    struct tm *lt = localtime(&t);

    // Define an array to hold the day names
    char* dayNames[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    // Print the result
    printf("The day on %02d-%02d-%04d is: %s\n", day, month, year, dayNames[lt->tm_wday]);

    return 0;
}

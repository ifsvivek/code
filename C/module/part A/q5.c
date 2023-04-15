/* An electricity board charges the following rates for the use of electricity:
for the first 200 units 80 Paise per unit: for the next 100 units 90 Paise per unit:
beyond 300 units Rs 1 per unit. All users are charged a minimum of Rs. 100 as Meter charge.
If the total amount is more than Rs 400, then an additional surcharge of 15% of total amount is charged.
Write a program to read the name of the user, number of units consumed and print out the charges. */

#include <stdio.h>
#include <conio.h>
void main()
{
    char name[20];
    float unit, price, extra;
    printf("Enter Consumer's Name: ");
    gets(name);
    printf("Enter Units of electricity used:");
    scanf("%f", &unit);
    if (unit <= 200)
    {
        price = (80 * unit) / 100 + 100;
        puts(name);
        printf("Units = %.2f \nRate = 80 Paise/Unit \nMeter charges = 100 \nPrice = %.2f", unit, price);
    }
    else if (unit > 200 && unit <= 300)
    {
        extra = unit - 200;
        price = (80 * unit) / 100 + 90 * extra / 100 + 100;
        puts(name);
        printf("\nUnits = %.2f \nRate = 80 Paise/Unit for first 200 Units and 90 Paise/Unit for next 100 Units \nMeter charges = 100 \nPrice = %.2f", unit, price);
    }
    else if (unit > 300 && unit <= 400)
    {
        price = unit + 100;
        puts(name);
        printf("\nUnits = %.2f \nRate = 1 Rupees/Unit \nMeter charges = 100 \nPrice = %.2f", unit, price);
    }
    else if (unit > 400)
    {
        price = unit + (0.15 * unit) + 100;
        puts(name);
        printf("\nUnits = %.2f \nRate = 1 Rupees/Unit \nExtra charges = 15% \nMeter charges = 100 \nPrice = %.2f", unit, price);
    }
}
//java prgram for converting temperature from celsius to fahrenheit and vice versa using if else statement and options menu

import java.util.Scanner;

class p6 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("1: celsius to fahrenheit \n2: fahrenheit to celsius");
        int choice = sc.nextInt();
        if (choice == 1) {
            System.out.println("Enter the temperature in celsius");
            double celsius = sc.nextDouble();
            double fahrenheit = (celsius * 9 / 5) + 32;
            System.out.println("The temperature in fahrenheit is " + fahrenheit);
        } else if (choice == 2) {
            System.out.println("Enter the temperature in fahrenheit");
            double fahrenheit = sc.nextDouble();
            double celsius = (fahrenheit - 32) * 5 / 9;
            System.out.println("The temperature in celsius is " + celsius);
        } else {
            System.out.println("Invalid choice");
        }
    }
}
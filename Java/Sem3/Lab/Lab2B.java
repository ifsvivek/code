
// 2B: A cloth showroom has announced the following discount on purchase of items based on the amount purchased. 
//write a program to calculate the bill amount after discount.
// Amount Discount
// <2000 5%
// 2000-5000 25%
// 5000-10000 35%
// >10000 50%

import java.util.Scanner;

public class Lab2B {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the total cost: ");
        double bill = s.nextDouble();
        if (bill < 2000)
            bill -= 0.05 * bill;
        else if (bill <= 5000)
            bill -= 0.25 * bill;
        else if (bill <= 1000)
            bill -= 0.35 * bill;
        else
            bill -= 0.5 * bill;
        System.out.println("Total Bill= " + bill);
    }
}

/*
 * Output:
 * 
 * Enter the total cost:
 * 1000
 * Total Bill= 650.0
 * 
 * Enter the total cost:
 * 5000
 * Total Bill= 3750.0
 * 
 * Enter the total cost:
 * 10000
 * Total Bill= 5000.0
 */
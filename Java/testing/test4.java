//java program for area of any shape

import java.util.Scanner;

public class test4 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of sides: ");
        int n = sc.nextInt();

        if (n == 0) {
            System.out.print("Enter the radius of the cicle: ");
            double r = sc.nextDouble();
            double area = 3.14 * r * r;
            System.out.println("Area of the cicle is: " + area);

        } else if (n == 3) {
            System.out.print("Enter the length of the triangle: ");
            double l = sc.nextDouble();
            System.out.print("Enter the breadth of the triangle: ");
            double b = sc.nextDouble();
            double area = 0.5 * l * b;
            System.out.println("Area of the triangle is: " + area);

        } else if (n == 4) {
            System.out.print("Enter the length of the rectangle: ");
            double l = sc.nextDouble();
            System.out.print("Enter the breadth of the rectangle: ");
            double b = sc.nextDouble();
            double area = l * b;
            System.out.println("Area of the square is: " + area);

        } else if (n == 5) {
            System.out.print("Enter the length of the pentagon: ");
            double l = sc.nextDouble();
            double area = 1.6 * l * l;
            System.out.println("Area of the pentagon is: " + area);

        } else if (n == 6) {
            System.out.print("Enter the length of the hexagon: ");
            double l = sc.nextDouble();
            double area = 2.2 * l * l;
            System.out.println("Area of the hexagon is: " + area);

        } else if (n == 7) {
            System.out.print("Enter the length of the heptagon: ");
            double l = sc.nextDouble();
            double area = 2.6 * l * l;
            System.out.println("Area of the heptagon is: " + area);

        } else if (n == 8) {
            System.out.print("Enter the length of the octagon: ");
            double l = sc.nextDouble();
            double area = 2.8 * l * l;
            System.out.println("Area of the octagon is: " + area);

        } else if (n == 9) {
            System.out.print("Enter the length of the nonagon: ");
            double l = sc.nextDouble();
            double area = 3.0 * l * l;
            System.out.println("Area of the nonagon is: " + area);

        } else if (n == 10) {
            System.out.print("Enter the length of the decagon: ");
            double l = sc.nextDouble();
            double area = 3.2 * l * l;
            System.out.println("Area of the decagon is: " + area);
        } else {
            System.out.println("Invalid input");
        }
    }

}
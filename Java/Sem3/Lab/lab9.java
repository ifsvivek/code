// Develop a JAVA program to raise a custom exception (user defined exception) for DivisionByZero using try, catch, throw and finally

import java.util.Scanner;

public class lab9 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        try {
            int c = a / b;
            System.out.println(c);
        } catch (Exception e) {
            System.out.println("Division by zero is not allowed");
        }
    }
}
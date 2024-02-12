// Develop a JAVA program to raise a custom exception (user defined exception) for DivisionByZero using try, catch, throw and finally

import java.util.Scanner;

class IException extends Exception {
    IException(String msg) {
        super(msg);
    }
}

public class lab9 {
    static void divide(double a, double b) throws IException {
        if (b == 0) {
            throw new IException("Division by zero is not allowed");
        }
        double c = a / b;
        System.out.println("Result= " + c);
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter two numbers: ");
        double a = sc.nextDouble();
        double b = sc.nextDouble();
        try {
            divide(a, b);
        } catch (IException e) {
            System.out.println(e);
        } finally {
            System.out.println("End");
        }
    }
}
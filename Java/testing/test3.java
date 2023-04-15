
//java program for calculator using loops with multiple numbers using array 
import java.util.Scanner;

public class test3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the number of numbers: ");
        int n = sc.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            System.out.print("Enter the number: ");
            a[i] = sc.nextInt();
        }
        System.out.print("Enter the operator: ");
        String op = sc.next();
        int sum = 0;
        if (op.equals("+")) {
            for (int i = 0; i < n; i++) {
                sum = sum + a[i];
            }
            System.out.println("Sum is: " + sum);
        } else if (op.equals("-")) {
            for (int i = 0; i < n; i++) {
                sum = sum - a[i];
            }
            System.out.println("Difference is: " + sum);
        } else if (op.equals("*")) {
            for (int i = 0; i < n; i++) {
                sum = sum * a[i];
            }
            System.out.println("Product is: " + sum);
        } else if (op.equals("/")) {
            for (int i = 0; i < n; i++) {
                sum = sum / a[i];
            }
            System.out.println("Quotient is: " + sum);
        } else {
            System.out.println("Invalid operator");
        }
    }

}
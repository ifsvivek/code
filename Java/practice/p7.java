//Java Program to Generate Fibonacci Series Numbers of First N Even Indexes
import java.util.Scanner;
public class p7 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of even indexes");
        int n = sc.nextInt();
        int a = 0, b = 1, c = 0;
        System.out.print(a + " " + b + " ");
        for (int i = 2; i < n; i++) {
            c = a + b;
            a = b;
            b = c;
            System.out.print(c + " ");
        }
    }
}
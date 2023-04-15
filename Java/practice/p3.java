
//Java Program to Check if a Given Integer is Odd or Even
import java.util.Scanner;

public class p3 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter an Integer: ");
        int n = sc.nextInt();
        if (n % 2 == 0) {
            System.out.println("Entered Integer is Even");
        } else {
            System.out.println("Entered Integer is Odd");
        }
    }
}
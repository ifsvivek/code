//Java Program to Copy All the Elements of One Array to Another Array

import java.util.Scanner;

public class p18 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        int b[] = new int[n];
        for (int i = 0; i < n; i++) {
            b[i] = a[i];
        }
        System.out.println("Copied array is ");
        for (int i = 0; i < n; i++) {
            System.out.print(b[i] + " ");
        }
    }

}

//Java Program to Compute the Sum of Diagonals of a Matrix

import java.util.Scanner;

public class p26 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows and columns");
        int n = sc.nextInt();
        int a[][] = new int[n][n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][i];
        }
        for (int i = 0; i < n; i++) {
            sum += a[i][n - i - 1];
        }
        System.out.println("Sum of diagonals is " + sum);
    }

}

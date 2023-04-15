//Java Program to Add two Matrices

import java.util.Scanner;

public class p21 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of rows");
        int n = sc.nextInt();
        System.out.println("Enter the number of columns");
        int m = sc.nextInt();
        int a[][] = new int[n][m];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                a[i][j] = sc.nextInt();
            }
        }
        System.out.println("Enter the number of rows");
        int p = sc.nextInt();
        System.out.println("Enter the number of columns");
        int q = sc.nextInt();
        int b[][] = new int[p][q];
        System.out.println("Enter the elements");
        for (int i = 0; i < p; i++) {
            for (int j = 0; j < q; j++) {
                b[i][j] = sc.nextInt();
            }
        }
        if (n == p && m == q) {
            int c[][] = new int[n][m];
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    c[i][j] = a[i][j] + b[i][j];
                }
            }
            System.out.println("The sum of two matrices is");
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < m; j++) {
                    System.out.print(c[i][j] + " ");
                }
                System.out.println();
            }
        } else {
            System.out.println("Matrices are not added");
        }
    }
}
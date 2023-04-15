//Java Program to Find the Determinant of a Matrix

import java.util.Scanner;

public class p23 {
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
        int det = 0;
        if (n == 1) {
            det = a[0][0];
        } else if (n == 2) {
            det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        } else {
            for (int i = 0; i < n; i++) {
                int b[][] = new int[n - 1][n - 1];
                for (int j = 1; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (k < i) {
                            b[j - 1][k] = a[j][k];
                        } else if (k > i) {
                            b[j - 1][k - 1] = a[j][k];
                        }
                    }
                }
                det += Math.pow(-1, i) * a[0][i] * determinant(b);
            }
        }
        System.out.println("Determinant is " + det);
    }

    public static int determinant(int a[][]) {
        int n = a.length;
        int det = 0;
        if (n == 1) {
            det = a[0][0];
        } else if (n == 2) {
            det = a[0][0] * a[1][1] - a[0][1] * a[1][0];
        } else {
            for (int i = 0; i < n; i++) {
                int b[][] = new int[n - 1][n - 1];
                for (int j = 1; j < n; j++) {
                    for (int k = 0; k < n; k++) {
                        if (k < i) {
                            b[j - 1][k] = a[j][k];
                        } else if (k > i) {
                            b[j - 1][k - 1] = a[j][k];
                        }
                    }
                }
                det += Math.pow(-1, i) * a[0][i] * determinant(b);
            }

        }
        return det;
    }
}
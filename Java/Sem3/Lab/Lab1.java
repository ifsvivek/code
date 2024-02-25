
// 1: Develop a Java program to add 2 matrices of order n [The order of the matrix is to be given as command line argument]. 
import java.util.Scanner;

public class Lab1 {

    public static void main(String[] args) {
        int i, j;
        if (args.length == 0) {
            System.out.println("Invalid Input");
            System.exit(0);
        }
        int n = Integer.parseInt(args[0]);
        int a[][] = new int[n][n];
        int b[][] = new int[n][n];
        int c[][] = new int[n][n];
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the value of Matrix A");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                a[i][j] = s.nextInt();
        }
        System.out.println("Enter the value of Matrix B");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                b[i][j] = s.nextInt();
        }
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                c[i][j] = a[i][j] + b[i][j];
        }
        System.out.println("Resultant Matrix");
        for (i = 0; i < n; i++) {
            for (j = 0; j < n; j++)
                System.out.print(c[i][j] + " ");
            System.out.println();
        }
    }
}

/*
 * Output:
 * javac Lab1.java
 * java Lab1 2
 * Enter the value of Matrix A
 * 1 2
 * 3 4
 * Enter the value of Matrix B
 * 5 6
 * 7 8
 * Resultant Matrix
 * 6 8
 * 10 12
 */
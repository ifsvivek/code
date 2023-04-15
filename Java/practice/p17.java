//Java Program to Find Common Elements Between Two Arrays

import java.util.Scanner;

public class p17 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the number of elements");
        int m = sc.nextInt();
        int b[] = new int[m];
        System.out.println("Enter the elements");
        for (int i = 0; i < m; i++) {
            b[i] = sc.nextInt();
        }
        int c[] = new int[n];
        int k = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (a[i] == b[j]) {
                    c[k++] = a[i];
                }
            }
        }
        System.out.println("Common elements are");
        for (int i = 0; i < k; i++) {
            System.out.print(c[i] + " ");
        }
    }

}

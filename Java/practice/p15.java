
//Java Program to Merge Two Arrays
import java.util.Scanner;

public class p15 {
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
        int c[] = new int[n + m];
        int i = 0;
        int j = 0;
        int k = 0;
        while (i < n && j < m) {
            if (a[i] < b[j]) {
                c[k++] = a[i++];
            } else {
                c[k++] = b[j++];
            }
        }
        while (i < n) {
            c[k++] = a[i++];
        }
        while (j < m) {
            c[k++] = b[j++];
        }
        System.out.println("Merged array is ");
        for (int l = 0; l < c.length; l++) {
            System.out.print(c[l] + " ");
        }
    }

}
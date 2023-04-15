//Java Program to Check if two Arrays are Equal or not

import java.util.Scanner;

public class p22 {
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
        if (n == m) {
            boolean flag = true;
            for (int i = 0; i < n; i++) {
                if (a[i] != b[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                System.out.println("Arrays are equal");
            } else {
                System.out.println("Arrays are not equal");
            }
        } else {
            System.out.println("Arrays are not equal");
        }
    }

}

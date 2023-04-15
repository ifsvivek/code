//Java Program For Array Rotation

import java.util.Scanner;

public class p19 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the number of rotations");
        int k = sc.nextInt();
        for (int i = 0; i < k; i++) {
            int temp = a[0];
            for (int j = 0; j < n - 1; j++) {
                a[j] = a[j + 1];
            }
            a[n - 1] = temp;
        }
        System.out.println("Rotated array is ");
        for (int i = 0; i < n; i++) {
            System.out.print(a[i] + " ");
        }
    }

}

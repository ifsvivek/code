
//Java Program for Linear Search
import java.util.Scanner;

public class p8 {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of elements");
        int n = sc.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements");
        for (int i = 0; i < n; i++) {
            a[i] = sc.nextInt();
        }
        System.out.println("Enter the element to be searched");
        int x = sc.nextInt();
        int flag = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] == x) {
                flag = 1;
                System.out.println("Element found at index " + i);
                break;
            }
        }
        if (flag == 0) {
            System.out.println("Element not found");
        }
    }
}

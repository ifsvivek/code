import java.util.Scanner;

class Elements {
    public static void main(String[] args) {
        int i;
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the Number ");
        int n = s.nextInt();
        int a[] = new int[n];
        System.out.println("Enter the elements of array");
        for (i = 0; i < n; i++) {
            a[i] = s.nextInt();
        }
        System.out.println("The elements are");
        for (i = 0; i < n; i++) {
            System.out.println(a[i]);
        }
    }
}
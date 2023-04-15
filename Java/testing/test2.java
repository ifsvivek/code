
//java program for identifing palindrome or not
import java.util.Scanner;

public class test2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter the string: ");
        String s = sc.nextLine();
        int n = s.length();
        int i = 0, j = n - 1;
        while (i < j) {
            if (s.charAt(i) != s.charAt(j)) {
                System.out.println("Not a palindrome");
                break;
            }
            i++;
            j--;
        }
        if (i >= j) {
            System.out.println("Palindrome");
        }
    }
}
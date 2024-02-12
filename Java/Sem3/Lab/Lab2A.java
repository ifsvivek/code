// 2A
import java.util.Scanner;

public class Lab2A {
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        System.out.println("Enter the total cost: ");
        double bill = s.nextDouble();
        if (bill < 2000) {
            bill -= 0.05 * bill;
        } else if (bill <= 5000) {
            bill -= 0.25 * bill;
        } else if (bill <= 1000) {
            bill -= 0.35 * bill;
        } else {
            bill -= 0.5 * bill;
        }
        System.out.println("Total Bill= " + bill);
    }
}
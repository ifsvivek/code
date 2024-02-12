// Develop a JAVA program to create a package named mypack and import & implement it in a suitable class. 
package mypack;
import java.util.Scanner;
public class test {
    int x;
    public int y;
    protected int z;
    private int p;
    Scanner s = new Scanner(System.in);

    public void read() {
        System.out.println("Enter values of x, y, z and p");
        x = s.nextInt();
        y = s.nextInt();
        z = s.nextInt();
        p = s.nextInt();
    }

    public void display() {
        System.out.println("x= " + x + "\ty= " + y + "\tz= " + z+ "\tp= " + p);
    }
}
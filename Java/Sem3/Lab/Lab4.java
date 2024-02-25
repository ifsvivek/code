/*4. A class called MyPoint, which models a 2D point with x and y coordinates, is designed as follows: 
● Two instance variables x (int) and y (int). 
● A default (or "no-arg") constructor that construct a point at the default location of (0, 0). 
● A overloaded constructor that constructs a point with the given x and y coordinates. 
● A method setXY() to set both x and y. 
● A method getXY() which returns the x and y in a 2-element int array.
● A toString() method that returns a string description of the instance in the format "(x, y)". 
● A method called distance(int x, int y) that returns the distance from this point to another point at the 
given (x, y) coordinates 
● An overloaded distance(MyPoint another) that returns the distance from this point to the given 
MyPoint instance (called another) 
● Another overloaded distance() method that returns the distance from this point to the origin (0,0) 
Develop the code for the class MyPoint. Also develop a JAVA program (called TestMyPoint) to test all the 
methods defined in the class.  */
class Mypoint {
    int x, y;

    Mypoint() {
        x = 0;
        y = 0;
    }

    Mypoint(int x, int y) {
        this.x = x;
        this.y = y;
    }

    void setXY(int x, int y) {
        this.x = x;
        this.y = y;
    }

    int[] getXY() {
        int a[] = new int[2];
        a[0] = x;
        a[1] = y;
        return a;
    }

    public String toString() {
        return "(" + x + "," + y + ")";
    }

    double Distance(int x, int y) {
        return Math.sqrt(Math.pow(this.x - x, 2) + Math.pow(this.y - y, 2));
    }

    double Distance() {
        return Math.sqrt(Math.pow(this.x, 2) + Math.pow(this.y, 2));
    }

    double Distance(Mypoint P2) {
        return Math.sqrt(Math.pow(this.x - P2.x, 2) + Math.pow(this.y - P2.y, 2));
    }
}

public class Lab4 {
    public static void main(String[] args) {
        Mypoint P1 = new Mypoint();
        Mypoint P2 = new Mypoint(10, 20);
        int a[] = P1.getXY();
        System.out.println("P1 X =" + a[0] + "\nP1 Y =" + a[1]);
        P1.setXY(5, 6);
        System.out.println("Point p1 =");
        System.out.println(P1);
        System.out.println("point p2=");
        System.out.println(P2);
        System.out.println("Distance between the point P1 & (2,3) is=" + P1.Distance(2, 3));
        System.out.println("Distance from P1 to origin =" + P1.Distance());
        System.out.println("Distance between P1 & P2 =" + P1.Distance(P2));
    }
}

/*
 * Output:

 * P1 X =0
 * P1 Y =0
 * Point p1 =
 * (5,6)
 * point p2=
 * (10,20)
 * Distance between the point P1 & (2,3) is=4.242640687119285
 * Distance from P1 to origin =7.810249675906654
 * Distance between P1 & P2 =14.866068747318506

 */
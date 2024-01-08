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

public class TestMyPoint {
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

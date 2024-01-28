// 6
abstract class Shape {
    abstract void calArea();

    abstract void calPeri();
}

class Circle extends Shape {
    double r;

    Circle(double r) {
        this.r = r;
    }

    void calArea() {
        System.out.printf("Area of Circle is %.4f\n", (3.14 * r * r));
    }

    void calPeri() {
        System.out.printf("Perimeter of Circle is %.4f\n", (2 * 3.14 * r));
    }

}

class Triangle extends Shape {
    double a, b, c;

    Triangle(double a, double b, double c) {
        this.a = a;
        this.b = b;
        this.c = c;
    }

    void calArea() {
        double s = (a + b + c) / 2;
        double area = Math.sqrt(s * (s - a) * (s - b) * (s - c));
        System.out.printf("Area of Triangle is %.4f\n", area);
    }

    void calPeri() {
        double s = a + b + c;
        System.out.printf("Perimeter of Triangle is %.4f\n", (s));
    }

}

public class ShapeB {
    public static void main(String[] args) {
        Shape obj = new Circle(10);
        obj.calArea();
        obj.calPeri();
        obj = new Triangle(4, 6, 7);
        obj.calArea();
        obj.calPeri();
    }

}
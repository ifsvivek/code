public class Triangle {
    private double side1, side2, side3;
    public Triangle() {
        side1 = side2 = side3 = 0;
    }
    public Triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }
    public double Area() {
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }
    public String Check() {
        if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2) {
            return "Not a Triangle";
        } else if (side1 == side2 && side2 == side3) {
            return "Equilateral Triangle";
        } else if (side1 == side2 || side2 == side3 || side1 == side3) {
            return "Isosceles Triangle";
        } else {
            return "Scalene Triangle";
        }
    }
    public static void main(String[] args) {
        Triangle triangle1 = new Triangle(3, 4, 5);
        System.out.println("Area of triangle1: " + triangle1.Area());
        System.out.println("Type of triangle1: " + triangle1.Check());

        Triangle triangle2 = new Triangle(5, 5, 5);
        System.out.println("Area of triangle2: " + triangle2.Area());
        System.out.println("Type of triangle2: " + triangle2.Check());

        Triangle triangle3 = new Triangle(2, 3, 7);
        System.out.println("Area of triangle3: " + triangle3.Area());
        System.out.println("Type of triangle3: " + triangle3.Check());
    }
}
public class triangle {
    private double side1, side2, side3;

    public triangle() {
        side1 = side2 = side3 = 0;
    }

    public triangle(double side1, double side2, double side3) {
        this.side1 = side1;
        this.side2 = side2;
        this.side3 = side3;
    }

    public double Area() {
        double s = (side1 + side2 + side3) / 2;
        return Math.sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    public String Check() {
        if (side1 + side2 <= side3 || side2 + side3 <= side1 || side1 + side3 <= side2)
            return "Not a Triangle";
        else if (side1 == side2 && side2 == side3)
            return "Equilateral Triangle";
        else if (side1 == side2 || side2 == side3 || side1 == side3)
            return "Isosceles Triangle";
        else
            return "Scalene Triangle";
    }

    public static void main(String[] args) {
        triangle triangle1 = new triangle(3, 4, 5);
        System.out.println("Area of triangle1: " + triangle1.Area());
        System.out.println("Type of triangle1: " + triangle1.Check());

        triangle triangle2 = new triangle(5, 5, 5);
        System.out.println("Area of triangle2: " + triangle2.Area());
        System.out.println("Type of triangle2: " + triangle2.Check());

        triangle triangle3 = new triangle(2, 3, 7);
        System.out.println("Area of triangle3: " + triangle3.Area());
        System.out.println("Type of triangle3: " + triangle3.Check());
    }
}
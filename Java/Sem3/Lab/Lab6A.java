// 6A
abstract class Shape {
    abstract void draw();

    abstract void erase();
}

class Circle extends Shape {
    void draw() {
        System.out.println("Circle Created");
    }

    void erase() {
        System.out.println("Circle Erased");
    }
}

class Triangle extends Shape {
    void draw() {
        System.out.println("Triangle Created");
    }

    void erase() {
        System.out.println("Triangle Erased");
    }
}

class Square extends Shape {
    void draw() {
        System.out.println("Square Created");
    }

    void erase() {
        System.out.println("Square Erased");
    }
}

public class Lab6A {
    public static void main(String[] args) {
        Shape obj = new Circle();
        obj.draw();
        obj.erase();
        obj = new Triangle();
        obj.draw();
        obj.erase();
        obj = new Square();
        obj.draw();
        obj.erase();

    }

}
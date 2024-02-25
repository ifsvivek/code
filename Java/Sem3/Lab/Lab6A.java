// 6A: Develop a Java program to create an abstract class named Shape. create three sub classes named Circle, Triangle and Square each 
// class has 2 member functions named draw() and erase(). Demonstrate the use of polymorphism concept by developing suitable
// methods defining member data and main function.
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

/*
 * Output:
 * Circle Created
 * Circle Erased
 * Triangle Created
 * Triangle Erased
 * Square Created
 * Square Erased
 
 */
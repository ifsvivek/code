// 8: Develop a Java program to create a class Outer with a function display().
// Create another class Inner with a function display() and call two functions in the main class.
class Outer {

    private int x = 10;

    class Inner {
        private int y = 20;

        void display() {
            System.out.println("X: " + x + " Y:" + y);
        }
    }

    void display() {
        Inner i = new Inner();
        i.display();
        System.out.println("Y: " + i.y);
    }
}

public class Lab8 {
    public static void main(String[] args) {
        Outer o = new Outer();
        Outer.Inner obj = o.new Inner();

        o.display();
        obj.display();
    }
}

/*
 * Output:
 * X: 10 Y:20
 * Y: 20
 */
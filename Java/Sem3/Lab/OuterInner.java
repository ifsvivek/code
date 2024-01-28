// 8
class Outer {

    class Inner {
        private int x = 10;
        private int y = 20;

        void display() {
            System.out.println("x + y = " + (x + y));
        }
    }

    void display() {
        Inner i = new Inner();
        i.display();
        System.out.println("y = " + i.y);
    }
}

public class OuterInner {
    public static void main(String[] args) {
        Outer o = new Outer();
        Outer.Inner obj = o.new Inner();

        o.display();
        obj.display();
    }
}
// 8
class Outer {

    private int x = 10;

    class Inner {
        private int y = 20;

        void display() {
            System.out.println("X: "+x+" Y:"+y);
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
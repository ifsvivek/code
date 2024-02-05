package access;

import mypack.test;

public class demo {
    public static void main(String[] args) {

        test t = new test();
        t.x = 10;
        t.y = 20;
        t.z = 30;
        t.p = 40;
        t.read();
        t.display();
    }
}
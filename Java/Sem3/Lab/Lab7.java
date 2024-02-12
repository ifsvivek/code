// 7
interface Resizable {
    void resizeWidth(int width);

    void resizeHeight(int height);
}

public class Lab7 implements Resizable {

    int height, width;

    Lab7(int height, int width) {
        this.height = height;
        this.width = width;
    }

    public void resizeHeight(int height) {
        this.height = height;
    }

    public void resizeWidth(int width) {
        this.width = width;
    }

    public static void main(String[] args) {
        Lab7 R = new Lab7(10, 20);
        System.out.println("height= " + R.height + " width= " + R.width);
        R.resizeHeight(100);
        R.resizeWidth(200);
        System.out.println("Updated\nheight= " + R.height + " width= " + R.width);

    }
}
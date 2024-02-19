// Producer Consumer Problem

class Buffer {
    int i, flag = 0;

    synchronized void put(int x) {
        try {
            if (flag == 1)
                wait();
        } catch (Exception e) {
            System.out.println(e);
        }
        i = x;
        System.out.println("Produced " + i);
        flag = 1;
        notify();
    }

    synchronized void get() {
        try {
            if (flag == 0)
                wait();
        } catch (Exception e) {
            System.out.println(e);
        }
        System.out.println("Consumed " + i);
        flag = 0;
        notify();
    }
}

class Producer implements Runnable {
    Buffer b;
    Thread t;

    Producer(Buffer b) {
        this.b = b;
        t = new Thread(this, "Producer");
        t.start();
    }

    public void run() {
        int i = 0;
        while (true) {
            b.put(i++);
        }
    }
}

class Consumer implements Runnable {
    Buffer b;
    Thread t;

    Consumer(Buffer b) {
        this.b = b;
        t = new Thread(this, "Consumer");
        t.start();
    }

    public void run() {
        while (true) {
            b.get();
        }
    }
}

public class Lab12 {

    public static void main(String args[]) {
        Buffer b = new Buffer();
        Producer p = new Producer(b);
        Consumer c = new Consumer(b);
    }
}
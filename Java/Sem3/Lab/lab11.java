// Write a program to illustrate creation of threads using runnable class.
// (start method start each of the newly created thread. Inside the run method
// there is sleep() for suspend the thread for 500 milliseconds).

public class lab11 {
    public static void main(String[] args) {
        Thread t = Thread.currentThread();
        System.out.println("Current Thread: " + t);
        t.setName("My Thread");
        System.out.println("After changing " + t);
        System.out.println("New Thread: " + t.getName());
        for (int i = 5; i >= 0; i--) {
            System.out.println(i);
            try {
                Thread.sleep(500);
            } catch (Exception e) {
                System.out.println("Interrupted");
            }
        }
    }
}
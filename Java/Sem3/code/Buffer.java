import java.io.*;

class Buffer {
    static void read() throws FileNotFoundException, IOException {
        FileReader f = new FileReader("C:\\Users\\vivek\\VS Code\\code\\other\\txt\\Demo.txt");
        try {
            BufferedReader r = new BufferedReader(f);
            System.out.println(r.readLine());
            throw new IOException("Unexpected Halt");
        } finally {
            System.out.println("File Closed");
            f.close();
        }
    }

    public static void main(String[] args) {
        try {
            read();
        } catch (Exception e) {
            System.out.println(e.getMessage());
        }
    }

}

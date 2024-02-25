// 2C: Write a program to initialize 10 array elements and find the sum of first 4 elements using enhanced for loop.
class Lab2C {
    public static void main(String[] args) {
        int sum = 0, count = 0;
        int a[] = { 10, 20, 30, 40, 50, 60, 70, 80, 90, 100 };
        for (int x : a) {
            sum = sum + x;
            count++;
            if (count == 4)
                break;
        }
        System.out.println("Sum= " + sum);
    }
}

/*
 * Output:
 * 
 * Sum= 100
 * 
 */
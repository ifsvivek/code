//You are given an array A of size N. You need to print elements of A in alternate order (starting from index 0).
import java.util.Scanner;

public class test5{
    public static void main(String[] args){
        Scanner sc=new Scanner(System.in);
        System.out.print("Enter the size of the array:");
        int size=sc.nextInt();
        int[] arr=new int[size];
        System.out.print("Enter first number of the array:");
        arr[0]=sc.nextInt();
        for(int j=1;j<size;j++){
            arr[j]=arr[j-1]+2;
        }
        for(int i=0;i<size;i++){
            System.out.println(arr[i]);
        }
    }
}
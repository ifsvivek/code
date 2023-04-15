/*Given an array of N integers arr[] where each element represents the max 
length of the jump that can be made forward from that element. Find the minimum number of jumps to 
reach the end of the array (starting from the first element). If an element is 0, then you cannot move 
through that element.*/


public class test6  {
        static int minJumps(int[] arr){
            // your code here
            int n = arr.length;
            if(n == 1){
                return 0;
            }
            if(arr[0] == 0){
                return -1;
            }
            int maxreach = arr[0];
            int step = arr[0];
            int jump = 1;
            for(int i =1;i<n;i++){
                if(i==n-1){
                    return jump;
                }
                maxreach = Math.max(maxreach,(i+arr[i]));
                
                step--;
                if(step==0){
                    jump++;
                    if(i>=maxreach){
                        return -1;
                    }
                    step = maxreach-i;
                }
            }
            return -1;
        }
    }
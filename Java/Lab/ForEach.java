class Foreach {
    public static void main(String[] args) {
        int sum=0,count=0;
        int a[]={1,4,9,16,25,36,64,81,100};
        for (int x : a) {
            sum=sum+x;
            count++;
            if(count==4)
            break;            
        }
       System.out.println("Sum= "+sum); 
    }
}

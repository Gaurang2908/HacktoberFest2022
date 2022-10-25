public class maxsubarray {
    public static void maxsubarray(int n[]){
        int cursum=0;
        int maxsum=Integer.MIN_VALUE;
        for(int i=0;i<n.length;i++){
            int start=i;
            for(int j=i;j<n.length;j++){
                int end=j;
                cursum=0;
                for(int k=start;k<=end;k++){
                    cursum+=n[k];
                }
                System.out.println(cursum);
                if(maxsum<cursum){
                    maxsum=cursum;
                }
            }
        }
        System.out.println("maxsum="+maxsum);
    }
    public static void main(String[] args) {
        int n[]={1,-2,6,-1,3};
        maxsubarray(n);

    }
}

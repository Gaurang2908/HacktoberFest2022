class Solution {
    public int[] sortArray(int[] nums) {
        int N = nums.length;
        mergeSort(nums, 0, N-1);
        return nums;
    }
    
    
    void mergeSort(int[] nums, int start, int end){
        if (end - start+1 <= 1) return; //Already sorted.
        int mi = start + (end - start)/ 2;
        mergeSort(nums, start, mi);
        mergeSort(nums, mi+1, end);
        merge(nums, start,mi, end);
    }
    
    void merge(int[] nums, int start, int mi, int end){
        int lp = start;
        int rp = mi + 1;
        int[] buffer = new int[end-start+1];
        int t = 0; //buffer pointer
        
        while (lp <= mi && rp <= end){
            if (nums[lp] < nums[rp]){
                buffer[t++] = nums[lp++];
            }else{
                buffer[t++] = nums[rp++];
            }
        }
        
        while (lp <= mi) buffer[t++] = nums[lp++];
        while (rp <= end) buffer[t++] = nums[rp++];
        //Now copy sorted buffer into original array
        for (int i = start; i <= end; i++){
            nums[i] = buffer[i-start];
        }
    }
    
    
}
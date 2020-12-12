class Solution {
    public void sortColors(int[] nums) {
        for(int i=1; i<nums.length; i++){
            int p = i;
            
            while(p>0 && nums[p]<nums[p-1]){
                int t = nums[p];
                nums[p] = nums[p-1];
                nums[p-1] = t;
                p--;
            }
        }

    }
}

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i=0, j=nums.size()-1;
        
        while(i<=j){
            int m = (i+j)/2;
            
            if(nums[m] == target) return m;
            
            if(nums[m] > nums[j]){
                if(target < nums[m] && target >= nums[i]){
                    j = m-1;
                }
                else{
                    i = m+1;
                }
            }
            else if(nums[m] < nums[i]){
                if(target > nums[m] && target <= nums[j]){
                    i = m+1;
                }
                else{
                    j = m-1;
                }
            }
            else{
                if(target>nums[m]){
                    i = m+1;
                }
                else{
                    j = m-1;
                }
            }
        }
        
        return -1;
    }
};

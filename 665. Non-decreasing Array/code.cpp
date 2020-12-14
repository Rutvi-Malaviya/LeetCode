class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int ind=-1;
        
        for(int i=1; i<nums.size(); i++){
            if(nums[i]<nums[i-1]){
                if(ind == -1){
                    ind = i-1;
                }
                else{
                    return false;
                }
            }
        }
        
        return ind==-1 ||  ind==0 || ind == nums.size()-2 || nums[ind-1]<=nums[ind+1] || nums[ind] <= nums[ind+2]; 
    }
};

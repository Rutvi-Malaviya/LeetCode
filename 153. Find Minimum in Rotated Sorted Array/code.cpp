class Solution {
public:
    int findMin(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        int i=0, j=nums.size()-1;
        
        int s=nums[0];
        
        
            int m = (i+j)/2;
            
            if(m>0 && nums[m]<nums[m-1]) return nums[m];
            
            if(nums[m]>nums[j]){
                vector<int> temp;
                temp.insert(temp.begin(), nums.begin()+m+1, nums.end());
                return findMin(temp);
            }
            else if(nums[m]<nums[i]){
                vector<int> temp;
                temp.insert(temp.begin(), nums.begin(), nums.begin()+m);
                return findMin(temp);
            }
            
        return s;
    }
};

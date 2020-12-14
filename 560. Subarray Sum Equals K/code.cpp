class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
      
        int sum = 0;
        int ans=0;
        map<int,int> sums;
        sums[0]=1;
        
        for(int i: nums){
            sum += i;
            if(sums.find(sum-k)!=sums.end()){
                ans += sums[sum-k];
            }
            sums[sum]++;
            
        }
        
        return ans;
    }
};

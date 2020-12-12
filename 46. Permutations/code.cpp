class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size()==1) return {nums};
        
        vector<vector<int>> ans;
        
        set<int> s;
        for(int i:nums) s.insert(i);
        
        for(int i: nums){
            s.erase(i);
            vector<int> v(s.begin(), s.end());
            vector<vector<int>> t = permute(v);
            
            for(auto a: t){
                a.insert(a.begin(), i);
                ans.push_back(a);
            }
            
            s.insert(i);
        }
        
        return ans;
    }
};

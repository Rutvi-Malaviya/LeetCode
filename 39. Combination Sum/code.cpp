class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        if(target==0) return {{}};
        
        vector<vector<int>> ans;
        for(int i: candidates){
            if(i>target) continue;
            vector<vector<int>> t = combinationSum(candidates, target-i);
            
            for(auto v: t){ 
                v.insert(v.begin(), i);
                sort(v.begin(), v.end());
                
                if(find(ans.begin(), ans.end(), v)==ans.end())
                    ans.push_back(v);
            }
        }
        
        return ans;
    }
};

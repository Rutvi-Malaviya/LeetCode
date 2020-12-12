class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> m;
        vector<vector<string>> ans;
        
        for(string s: strs){
            string t = s;
            sort(t.begin(), t.end());
            
            m[t].push_back(s);
        }
        
        for(auto a: m){
            ans.push_back(a.second);
        }
        
        return ans;
    }
};

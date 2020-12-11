class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        
        int n = strs[0].size();
        
        string ans="";
        
        for(int i=0; i<n; i++){
            char c = strs[0][i];
            for(int j=1; j<strs.size(); j++){
                if(strs[j][i]!=c) return ans;
            }
            
            ans += c;
        }
        
        return ans;
    }
};

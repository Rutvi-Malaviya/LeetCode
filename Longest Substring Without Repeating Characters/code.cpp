class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int start = 0;
        
        int maxLen = 0;
        
        map<char,int> m;
        
        int temp=0;
        
        for(int i=0; i<s.size(); i++){
            // cout << s[i] << endl;
            
            if(m.find(s[i])==m.end()){
                m[s[i]] = i;
                temp++;   
            }
            else{
                if(maxLen<temp) maxLen = temp;
                
                temp -= (m[s[i]]-start);
                int t = m[s[i]];
                for(int j = start; j<=m[s[i]]; j++){
                    m.erase(m.find(s[j]));
                }
                
                m[s[i]]=i;
                start = t+1;
            }
            
            // cout << " temp: " << temp << endl;
        }
        
        if(maxLen<temp) maxLen = temp;
        
        return maxLen;
    }
};

class Solution {
public:
    string reverseWords(string s) {
        string t="";
        
        string ans="";
        
        for(char c: s){
            if(c==' '){
                reverse(t.begin(), t.end());
                ans += t;
                ans += c;
                t="";
            }
            else{
                t += c;
            }
        }
        
        reverse(t.begin(), t.end());
        ans += t;
        
        
        return ans;
    }
};

class Solution {
public:
    string decodeString(string s) {
        
        // cout << s << endl;
        
        string ans="";
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(isalpha(c)){
                ans += c;
            }
            else{
                string temp="";
                
                while(s[i]!='['){
                    temp += s[i];
                    i++;
                }
                
                int repNum = stoi(temp);
                temp = "";
                i++;
                
                int ignore=0;
                while(s[i]!=']' || ignore){
                    temp += s[i];
                    if(s[i]==']') ignore--;
                    if(s[i]=='[') ignore++;
                    i++;
                }
                
                string t = decodeString(temp);
                
                while(repNum--){
                    ans += t;
                }
            }
        }
        
        return ans;
    }
};

class Solution {
public:
    int calculate(string s) {
        int n1=0, ans=0;
        string t="";
        
        char op = '+';
        set<char> sign = {'+','-','*','/'};
        
        for(int i=0; i<s.size(); i++){
            char c = s[i];
            if(sign.count(c)){
                // cout << n1 << endl;
                if(op=='+'){
                    ans += n1;
                    n1 = stoi(t);
                }
                if(op=='-'){
                    ans += n1;
                    n1 = -stoi(t);
                }
                if(op=='*'){
                    n1 = n1*stoi(t);
                }
                if(op=='/'){
                    n1 = n1/stoi(t);
                }
                
                op = c;
                t="";
                continue;
            }
            
            if(c=='('){
                string temp = "";
                int ignore=0;
                i++;
                while(s[i]!=')'||ignore>0){
                    if(s[i]=='('){
                        ignore++;
                    } 
                    if(s[i]==')'){
                        ignore--;
                    }
                    
                    temp += s[i];
                    i++;
                }
                
                t = to_string(calculate(temp));
                continue;
            }
            
            t+=c;
        }
        
        if(op=='+'){
            ans += n1+stoi(t);
        }
        if(op=='-'){
            if(t=="2147483648")
                ans += n1 - 2147483648;
            else
                ans += n1-stoi(t);
        }
        if(op=='*'){
            ans += n1*stoi(t);
        }
        if(op=='/'){
            ans += n1/stoi(t);
        }
        
        return ans;
        
    }
};

class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        
        int ans=0, n1=0 ;
        string t="";
        
        set<char> sign = {'+','-','*','/'};
        char op = '+';
        
        for(char c: s){
            if(sign.count(c)){
                
                if(op=='+'){
                    ans += n1;
                    n1 = stoi(t);
                }
                else if(op=='-'){
                    ans += n1;
                    n1 = -stoi(t);
                }
                else if(op=='*'){
                    n1 = n1*stoi(t);
                } 
                else{
                    n1 = n1/stoi(t); 
                }
                
                op = c;
                t="";
                
                continue;
            }
            
            t += c;
        }
        
        if(op=='+'){
            ans += n1;
            n1 = stoi(t);
        }
        else if(op=='-'){
            ans += n1;
            n1 = -stoi(t);
        }
        else if(op=='*'){
            n1 = n1*stoi(t);
        } 
        else{
            n1 = n1/stoi(t); 
        }
        
        ans += n1;
        
        return ans;
    }
};

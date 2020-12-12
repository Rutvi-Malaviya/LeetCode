class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        if(digits.size()==0) return {};
        
        map<char, vector<char>> m;
        
        
        // cout <÷< "here ";
        
        m['2'] = {'a','b','c'};
        m['3'] = {'d','e','f'};
        m['4'] = {'g','h','i'};
        m['5'] = {'j','k','l'};
        m['6'] = {'m','n','o'};
        m['7'] = {'p','q','r','s'};
        m['8'] = {'t','u','v'};
        m['9'] = {'w','x','y','z'};
        
        vector<string> ans = {""};
        
        for(char c: digits){
            vector<string> temp;
            
            for(char a: m[c]){
                for(string s: ans){
                    temp.push_back((s+a));
                }
            }
            
            
            // for(string s1: temp) cout << s1 << endl;
            
            ans = temp;
        }
        
        return ans;
    }
};

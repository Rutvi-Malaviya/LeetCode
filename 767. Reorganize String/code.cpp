class Solution {
public:
    string reorganizeString(string S) {
        map<char, int> m;
        
        for(char c: S) m[c]++;
        
        map<int, set<char>, greater<int>> m2;
        
        for(auto a: m) m2[a.second].insert(a.first);
        
        vector<char> v(S.size(), '0');
        
//         for(auto a: m2){
//             cout << a.first << ": ";
            
//             for(char c: a.second)
//                 cout << c << " ";
            
//             cout << endl;
//         }
        
        int start = 0;
        int i=0;
        for(auto a: m2){
    
            for(char c: a.second){
                int n = a.first;
                
                while(n--){
                    if(i>=v.size()){
                        i = start;
                        
                        while(i<v.size() && v[i]!='0') i++;
                        start = i;
                        
                        if(i==v.size()) return "";
                    } 

                    if((i>0 && v[i-1]==c) || (i<v.size()-1 && v[i+1]==c)) return "";
                    v[i] = c;
                    i+=2;
                }
            }
            
            // for(char c: v) cout << c << " ";
            // cout << endl;
            
        }
        
        string ans="";
        
        for(char c: v) ans += c;
        
        return ans;
    }
};

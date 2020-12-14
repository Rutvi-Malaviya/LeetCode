class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int W) {
        if(hand.size()%W) return false;
        
        map<int, int> m;
        
        for(int i: hand) m[i]++;
        
        int n = hand.size()/W;
        
        while(m.size()){
            // cout << n << endl;
            int prev = -1;
            int c=0;
            for(auto a: m){
                if(prev!=-1 && a.first!=prev+1) return false;
                
                // cout << a.first << " ";
                c++;
                prev = a.first;
                
                m[a.first] = a.second-1;
                
                if(m[a.first]==0) m.erase(a.first);
                
                if(c==W) break;
            }
            
            if(c!=W) return false;
            // cout << endl;
        }
        
        return true;
    }
};

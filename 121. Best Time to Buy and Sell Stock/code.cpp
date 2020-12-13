class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        
        int maxProfit=0;
        int m = prices[0];
        
        for(int i: prices){
            if(i-m>maxProfit) maxProfit = i-m;
            
            if(i<m) m=i;
        }
        
        return maxProfit;
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int> eleFreq;
        map<int, set<int>, greater<int>>freqEle;
        
        for(int i: nums){
            int freq = eleFreq[i];
            if(freq>0){
                freqEle[freq].erase(i);
            }
            
            eleFreq[i]++;
            freqEle[freq+1].insert(i);
        }
        
        vector<int> ans;
        
        for(auto a: freqEle){
            for(int i: a.second){
                ans.push_back(i);
                if(ans.size()==k) return ans;
            }
        }
        
        return ans;
    }
};

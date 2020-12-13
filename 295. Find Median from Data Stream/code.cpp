class MedianFinder {
public:
    /** initialize your data structure here. */
    
    vector<double> v;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(v.size()==0){
            v.push_back(num);
            return;
        }
        
        v.insert(lower_bound(v.begin(), v.end(), num), num);
    }
    
    double findMedian() {
        int n = v.size();
        
        if(n&1) return v[(n-1)/2];
        
        return (v[n/2]+v[(n/2)-1])/2;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

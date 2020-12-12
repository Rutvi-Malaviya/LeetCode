class Solution {
public:
    double myPow(double x, int n) {
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n==-1) return 1/x;
        
        
        bool neg = n<0;
        
        if(n&1){
            
            double p;
            
            if(neg){
                p = myPow(x, ((n+1)/2));
                return p*p*(1/x);
            }
            else{
                p = myPow(x, ((n-1)/2));
                return p*p*x;
            }
        }
        else{
            double p = myPow(x,(n/2));
            return p*p;
        }
    }
};

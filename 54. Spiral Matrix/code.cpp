class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
    
        int m = matrix.size();
        int n = matrix[0].size();
        int fr=0, tr=m-1, fc=0, tc=n-1;
        
        bool row = true, rrev=false, crev=false;
        vector<int> ans;
        
        while(ans.size()<m*n){
            if(row){
                if(rrev){
                    for(int i=tc; i>=fc; i--) ans.push_back(matrix[tr][i]);
                    tr--;
                }
                else{
                    for(int i=fc; i<=tc; i++) ans.push_back(matrix[fr][i]);
                    fr++;
                }
                rrev = !rrev;
                row = !row;
            }
            else{
                if(crev){
                    for(int i=tr; i>=fr; i--) ans.push_back(matrix[i][fc]);
                    fc++;
                }
                else{
                    for(int i=fr; i<=tr; i++) ans.push_back(matrix[i][tc]);
                    tc--;
                }
                
                crev = !crev;
                row = !row;
            }
        }
        
        return ans;
        
    }
};

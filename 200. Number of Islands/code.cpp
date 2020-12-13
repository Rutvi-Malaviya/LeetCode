class Solution {
public:
    
    void traverse(vector<vector<char>>& grid, int i, int j){
        int m = grid.size();
        int n = grid[0].size();
        
        if(i<0 || i>=m || j<0 || j>=n) return;
        
        grid[i][j] = '0';
        
        if(i>0 && grid[i-1][j]=='1') traverse(grid, i-1, j);
        if(i<m-1 && grid[i+1][j]=='1') traverse(grid, i+1, j);
        if(j>0 && grid[i][j-1]=='1') traverse(grid, i, j-1);
        if(j<n-1 && grid[i][j+1]=='1') traverse(grid, i, j+1);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int num=0;
        
        for(int i=0; i<grid.size(); i++){
            for(int j=0; j<grid[0].size(); j++){
                if(grid[i][j]=='1'){
                    num++;
                    traverse(grid, i, j);
                }
            }
        }
        
        return num;
    }
};

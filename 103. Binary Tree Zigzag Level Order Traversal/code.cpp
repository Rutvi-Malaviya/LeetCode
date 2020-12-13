/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    vector<vector<int>> traverse(TreeNode *root){
        if(!root) return {};
        
        vector<vector<int>> ans;
        ans.push_back({root->val});
        
        vector<vector<int>> l = traverse(root->left);
        vector<vector<int>> r = traverse(root->right);
        
        if(l.size()>r.size()){
            int i=0;
            
            for(i=0; i<r.size(); i++){
                l[i].insert(l[i].end(), r[i].begin(), r[i].end());
                ans.push_back(l[i]);
            }
            
            while(i<l.size()){
                ans.push_back(l[i]);
                i++;
            }
        }
        else{
            int i=0;
            
            for(i=0; i<l.size(); i++){
                l[i].insert(l[i].end(), r[i].begin(), r[i].end());
                ans.push_back(l[i]);
            }
            
            while(i<r.size()){
                ans.push_back(r[i]);
                i++;
            } 
        }
        
        return ans;
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans = traverse(root);
        
        
        for(int i=0; i<ans.size(); i++){
            if(i&1){
                reverse(ans[i].begin(), ans[i].end());
            }
        }
        
        return ans;
        
    }
};

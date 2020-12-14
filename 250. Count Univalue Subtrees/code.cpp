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
    
    pair<int,int> uniValue(TreeNode *root){
        if(!root) return {0,0};
        
        if(!root->left && !root->right) return {1,1};
        
        if(!root->left){
            auto r = uniValue(root->right);
            if(r.first && root->right->val==root->val) 
                return {1,r.second+1};
            else{
                return {0,r.second};
            }
        }
        
        if(!root->right){
            auto l = uniValue(root->left);
            if(l.first && root->left->val==root->val) 
                return {1,l.second+1};
            else
                return {0,l.second};
        }
        
        auto r = uniValue(root->right);
        auto l = uniValue(root->left);
        if(l.first && r.first && root->right->val == root->left->val && root->val==root->right->val)
            return {1,l.second+r.second+1};
        else
            return {0,l.second+r.second};
        
    }

    
    int countUnivalSubtrees(TreeNode* root) {
        if(!root) return 0;
        
        return uniValue(root).second;
        
    }
};

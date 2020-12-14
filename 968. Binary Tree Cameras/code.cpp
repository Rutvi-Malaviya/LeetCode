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
    
    set<TreeNode *> s;
    int ans=0;
    
    void dfs(TreeNode *root, TreeNode *parent){
        if(root==NULL) return;
        
        dfs(root->left, root);
        dfs(root->right, root);
        
        if((!parent && !s.count(root)) || !s.count(root->left) || !s.count(root->right)){
            ans++;
            s.insert(root);
            s.insert(root->left);
            s.insert(root->right);
            s.insert(parent);
        }
    }
    
    int minCameraCover(TreeNode* root) {
        s.insert(NULL);
        dfs(root, NULL);
        return ans;
    }
};

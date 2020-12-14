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
    void addLeaves(TreeNode *root, vector<int> &ans){
        if(!root) return;
        
        if(!root->left && !root->right){
            ans.push_back(root->val);
            return;
        }
        
        addLeaves(root->left, ans);
        addLeaves(root->right, ans);
    }
    
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        if(!root) return {};
        
        vector<int> ans;
        if(root->left || root->right) ans.push_back(root->val);
        TreeNode *t = root->left;
        
        while(t){
            if(t->left || t->right) ans.push_back(t->val);
            
            if(t->left) t = t->left;
            else t = t->right;
        }
        
        addLeaves(root, ans);
        
        stack<int> st;
        t = root->right;
        
        while(t){
            if(t->left || t->right) st.push(t->val);
            
            if(t->right) t = t->right;
            else t = t->left;
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};

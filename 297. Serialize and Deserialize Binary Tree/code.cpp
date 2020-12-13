/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        
        queue<TreeNode *> q;
        q.push(root);
        
        while(q.size()){
            TreeNode *t = q.front();
            q.pop();
            
            if(!t){
                s += "null ";
                continue;
            }
            
            s += to_string(t->val) +" ";
            q.push(t->left);
            q.push(t->right);
        }
        
        // cout << s << endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data=="null ") return NULL;
        stringstream ss(data);
        vector<string> v;
        string value;
        
        while(getline(ss,value,' ')){
            v.push_back(value);
        }
        
        TreeNode *root = new TreeNode(stoi(v[0]));
        queue<TreeNode *> q;
        q.push(root);
        
        int l=0;
        int ind=0;
        while(q.size()){
                TreeNode *t = q.front(); q.pop();
                if(v[2*l+1]!="null"){
                    t->left = new TreeNode(stoi(v[2*ind+1]));
                    q.push(t->left);
                }

                if(v[2*l+2]!="null"){
                    t->right = new TreeNode(stoi(v[2*ind+2]));
                    q.push(t->right);
                }
                
                ind++;
            
            
            l++;
        }
        
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    
    private boolean isSame(TreeNode l, TreeNode r){
        if(l==null) return (r==null);
        if(r==null) return (l==null);
        
        if(l.val==r.val){
            return isSame(l.left, r.right) && isSame(l.right, r.left);
        }
        
        return false;
    }
    
    public boolean isSymmetric(TreeNode root) {
        if(root==null) return true;
        
        return isSame(root.left, root.right);
    }
}

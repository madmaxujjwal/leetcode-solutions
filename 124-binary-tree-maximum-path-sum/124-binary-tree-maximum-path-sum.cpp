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
    int dfs(TreeNode* root,int &c){
        if(root==nullptr)
            return 0;
        int l=dfs(root->left,c);
        int r=dfs(root->right,c);
        int s=root->val;
        c=max(c,max(s+l+r,max(s,max(s+l,s+r))));
        return s+max(0,max(l,r));
        
        
    }
    int maxPathSum(TreeNode* root) {
        int c=INT_MIN;
        int ans=dfs(root,c);
        return c;
    }
};
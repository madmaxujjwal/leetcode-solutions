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
        int z=1;
        if(root->left!=nullptr&&root->val==root->left->val){
            z+=l;
            
        }
        else{
            l=0;
        }
        if(root->right!=nullptr&&root->val==root->right->val){
            z+=r;
        }
        else{
            r=0;
        }
        c=max(c,z);
        return 1+max(l,r) ;
    }
    int longestUnivaluePath(TreeNode* root) {
        
        int c=1;
        int ans=dfs(root,c);
        return c-1;
        
        
    }
};
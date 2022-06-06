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
    int height(TreeNode* root){
        if(root==nullptr)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    void dfs(TreeNode* root,int h,int d,int c, vector<vector<string>> &ans){
        if(root==nullptr)
            return;
        ans[h][c]=to_string(root->val);
        dfs(root->left,h+1,d-1,c-pow(2,d),ans);
        dfs(root->right,h+1,d-1,c+pow(2,d),ans);
        
        
    }
    vector<vector<string>> printTree(TreeNode* root) {
        int n=height(root);
        int m=pow(2,n)-1;
        vector<vector<string>> ans(n,vector<string>(m,""));
        dfs(root,0,n-2,m/2,ans);
        return ans;
        
        
    }
};
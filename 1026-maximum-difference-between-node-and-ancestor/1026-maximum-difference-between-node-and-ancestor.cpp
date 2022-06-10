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
    void dfs(TreeNode* root,int maxi,int mini,int &ans){
        if(root==nullptr)
            return;
        int v=root->val;
        ans=max(ans,max(abs(v-maxi),abs(v-mini)));
        dfs(root->left,max(maxi,v),min(mini,v),ans);
        dfs(root->right,max(maxi,v),min(mini,v),ans);
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int ans=0;
        int maxi=root->val;
        int mini=root->val;
        dfs(root,maxi,mini,ans);
        return ans;
        
    }
};
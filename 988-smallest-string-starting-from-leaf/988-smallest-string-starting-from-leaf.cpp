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
    void dfs(TreeNode* root,string z,string &maxi){
        if(root==nullptr)
            return;
        z=char(root->val+97)+z;
        if(root->left==nullptr&&root->right==nullptr)
        maxi=min(maxi,z);
        dfs(root->left,z,maxi);
        dfs(root->right,z,maxi);
        
    }
    string smallestFromLeaf(TreeNode* root) {
        string z="";
        string maxi="zzzz";
        dfs(root,z,maxi);
        return maxi;
    }
};
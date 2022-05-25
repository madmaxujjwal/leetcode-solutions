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
    bool bst(TreeNode* root,long a,long b){
        if(root==nullptr)
            return true;
        return (root->val>a)&&(root->val<b)&&bst(root->left,a,root->val)&&bst(root->right,root->val,b);
    }
    bool isValidBST(TreeNode* root) {
        if(root->left==nullptr&&root->right==nullptr)
            return true;
        return bst(root,(long)2*INT_MIN,(long)2*INT_MAX);
        
    }
};
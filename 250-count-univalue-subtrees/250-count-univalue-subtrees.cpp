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
    int dfs(TreeNode* root){
        if(root==nullptr)
            return 0;
        int a=dfs(root->left);
        int b=dfs(root->right);
        if(a<0||b<0||(root->left!=nullptr&&root->left->val!=root->val)||(root->right!=nullptr&&root->right->val!=root->val))
            return 0-abs(a)+0-abs(b);
        else{
            return 1+a+b;
        }    
            
    }
    int countUnivalSubtrees(TreeNode* root) {
        return abs(dfs(root));
    }
};
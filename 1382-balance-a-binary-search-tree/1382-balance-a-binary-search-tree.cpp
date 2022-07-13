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
    vector<int> in;
    int n;
    int size(TreeNode* root){
        if(root==nullptr)
            return 0;
        return 1+size(root->left)+size(root->right);
    }
    void dfs(TreeNode* root){
        if(root==nullptr)
            return;
        dfs(root->left);
        if(root!=nullptr)
        in.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* rec(int l,int r){
        if(l>r)
            return nullptr;
        if(l==r){
            return new TreeNode(in[l]);
        }
        int m=(l+r)/2;
        TreeNode* x=new TreeNode(in[m]);
        x->left=rec(l,m-1);
        x->right=rec(m+1,r);
        return x;
        
        
    }
    TreeNode* balanceBST(TreeNode* root) {
        n=size(root);
        dfs(root);
        return rec(0,n-1);
    }
};
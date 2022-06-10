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
    void dfs(TreeNode* &root,int d,int v,int h){
        if(root==nullptr)
            return;
        if(h==d){
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        TreeNode* x=new TreeNode(v);
        TreeNode* y=new TreeNode(v);
        root->left=x;
        root->right=y;
        x->left=l;
        y->right=r;
            
        }
        else{
            dfs(root->left,d,v,h+1);
            dfs(root->right,d,v,h+1);
        }
        
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
             TreeNode* x=new TreeNode(val);
            x->left=root;
            return x;
        }
        dfs(root,depth-1,val,1);
        return root;
    }
};
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
    int s;
    int sum(TreeNode* root){
        if(root==nullptr)
            return 0;
        return root->val+sum(root->left)+sum(root->right);
    }
    int res(TreeNode* root,bool &c,int z){
        if(c)
            return 0;
        if(root==nullptr)
            return 0;
        int sum=root->val+res(root->left,c,z+1)+res(root->right,c,z+1);
        if(2*sum==s&&z!=0){
            c=true;
            
        }
        return sum;
    }
    bool checkEqualTree(TreeNode* root) {
        s=sum(root);bool c=false;
        int z=res(root,c,0);
        return c;
    }
};
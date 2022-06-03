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
    void trav(TreeNode* root,unordered_map<TreeNode*,int> &ht,int &maxi){
        if(root==nullptr)
            return;
        if(ht[root]!=0){
            maxi=max(maxi,ht[root]);
        }
        else{
            dfs(root,ht);
        }
        trav(root->left,ht,maxi);
        trav(root->right,ht,maxi);
    }
    int dfs(TreeNode*root,unordered_map<TreeNode*,int> &ht){
        
        int x=1;int y=1;
        if(root==nullptr)
            return 0; 
        if((root->left!=nullptr)&&(root->val)==(root->left->val-1)){
         x=1+dfs(root->left,ht);
        }
        if((root->right!=nullptr)&&(root->val)==(root->right->val-1)){
            y=1+dfs(root->right,ht);
        }
        return ht[root]=max(x,y);
        
    }
    int longestConsecutive(TreeNode* root) {
       unordered_map<TreeNode*,int> ht;
        int maxi=0;
        trav(root,ht,maxi);
        return maxi+1;
    }
};
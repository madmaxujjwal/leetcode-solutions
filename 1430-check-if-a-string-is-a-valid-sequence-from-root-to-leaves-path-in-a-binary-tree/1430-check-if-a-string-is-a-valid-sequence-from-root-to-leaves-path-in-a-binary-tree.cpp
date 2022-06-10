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
    bool dfs(TreeNode* root,vector<int> &z,vector<int> arr,bool &c){
        if(c==true)
            return true;
        if(root==nullptr){
            return false;
        }
        z.push_back(root->val);
        if(root->left==nullptr&&root->right==nullptr){
            if(z==arr){
              c=true;  return true;}
        }
     bool s=false;
        
        s=s|dfs(root->left,z,arr,c);
        s=s|dfs(root->right,z,arr,c);
        z.pop_back();
        return s;
    }
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
    vector<int> z;
        bool c=false;
        return dfs(root,z,arr,c);
        
    }
};
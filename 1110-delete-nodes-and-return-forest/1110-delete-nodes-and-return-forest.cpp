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
    vector<int> d;
    unordered_map<TreeNode*,int> ht;
    void dfs(TreeNode* &root){
        if(root==nullptr)
            return ;
        TreeNode* l=root->left;
        TreeNode* r=root->right;
        if(d[root->val]==1){
            if(root->left!=nullptr)
                ht[root->left]++;
            if(root->right!=nullptr)
                ht[root->right]++;
           
            
        }
         if(root->left!=nullptr&&d[root->left->val]==1){
             root->left=nullptr;
             
         }
        if(root->right!=nullptr&&d[root->right->val]==1){
             root->right=nullptr;
             
         }
        
        dfs(l);
        dfs(r);
        
        
    }
    
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        d.resize(1001);
        for(int i=0;i<=1000;i++){
            d[i]=0;
        }
        for(auto it:to_delete){
            d[it]=1;
        }
        
        dfs(root);
        
        vector<TreeNode*> ans;
        for(auto it: ht){
            if(it.second>=1&&(d[it.first->val]==0)){
                ans.push_back(it.first);
            }
        }
        if(d[root->val]!=1)
        ans.push_back(root);
        return ans;
    }
};
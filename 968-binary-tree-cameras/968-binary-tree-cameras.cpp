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
    map<pair<TreeNode*,int>,int> dp;
    int rec(TreeNode* root,int c){
         if(root==nullptr&&c==2){
             return 1000000;
         }
        if(root==nullptr)
            return 0;
       if((root->left==nullptr)&&(root->right==nullptr)&&c>0){
           return 1;
       }
        
        if(dp.find({root,c})!=dp.end()){
            return dp[{root,c}];
        }
       
        if(c==0){
            return dp[{root,c}]=min(1+rec(root->left,0)+rec(root->right,0),min(rec(root->left,2)+rec(root->right,1),min(rec(root->left,2)+rec(root->right,2),min(rec(root->left,1)+rec(root->right,1),rec(root->left,1)+rec(root->right,2)))));
        }
        else if(c==1){
            return dp[{root,c}]=min(1+rec(root->left,0)+rec(root->right,0),min(rec(root->left,2)+rec(root->right,1),min(rec(root->left,2)+rec(root->right,2),rec(root->left,1)+rec(root->right,2))));
        }
        else{
            return dp[{root,c}]=1+ rec(root->left,0)+rec(root->right,0);
        }
    }
    int minCameraCover(TreeNode* root) { 
        
        int ans=rec(root,1);
       if(ans==0)
        return 1;
        return ans;
    }
};
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
    int ans;
    int rec(TreeNode* root,bool v){
        if(dp.find({root,v})!=dp.end())
            return dp[{root,v}];
        if(root==nullptr)
            return 0;
        if(v){
            if(dp.find({root,v})==dp.end())
            dp[{root,v}]=1+rec(root->left,!v); 
            if(dp.find({root,!v})==dp.end())
            dp[{root,!v}]=1+rec(root->right,v); 
        }
        else{
            if(dp.find({root,v})==dp.end())
            dp[{root,v}]=1+rec(root->right,!v);
            if(dp.find({root,!v})==dp.end())
             dp[{root,!v}]=1+rec(root->left,v); 
        }
        ans=max(ans,dp[{root,!v}]);
        ans=max(ans,dp[{root,v}]);
        return dp[{root,v}];
        
    }
    int longestZigZag(TreeNode* root) {
        ans=0;
        int a=rec(root,true);
        int b=rec(root,false);
        return ans-1;
    }
};
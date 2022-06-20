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
     int m=1e9+7;
    long long int sum(TreeNode* root){
        if(root==nullptr)
            return 0;
        return ((root->val)+sum(root->left)+sum(root->right));
    }
   long long int dfs(TreeNode* root,long long int &maxi,long long int sum){
        if(root==nullptr)
            return 0;
        long long int l=dfs(root->left,maxi,sum);
        long long int r=dfs(root->right,maxi,sum);
        maxi=max(maxi,(l*((sum-l))));
        maxi=max(maxi,(r*((sum-r))));
        return l+r+root->val ;
    }
    int maxProduct(TreeNode* root) {
        
       long long int s=sum(root);
        long long int maxi=INT_MIN;
        long long int ans=dfs(root,maxi,s);
        return maxi%m;
    }
};
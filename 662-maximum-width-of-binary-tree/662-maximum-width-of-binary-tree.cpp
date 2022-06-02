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
    int height(TreeNode* root){
        if(root==nullptr)
            return 0;
        int lh=height(root->left);
        int rh=height(root->right);
        return 1+max(lh,rh);
    }
    void dfs(TreeNode* root,int d,unsigned long long int w,int h, vector<pair<unsigned long long int,unsigned long long int>> &v){
        if(root==nullptr)
            return;
        if(v[d].first>w){
            v[d].first=w;
        }
         if(v[d].second<w){
            v[d].second=w;
        }
        dfs(root->left,d+1,2*w,h,v);
        dfs(root->right,d+1,2*w+1,h,v);
    }
    int widthOfBinaryTree(TreeNode* root) {
        int n=height(root);
        vector<pair<unsigned long long int,unsigned long long int>> v(n,{18446744073709551615,0});
        dfs(root,0,0,n,v);
        unsigned long long int ans=1;
        for(int i=0;i<n;i++){
            ans=max(ans,v[i].second-v[i].first+1);
        }
        return ans;
    }
};
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
    tuple<int,int,int> dfs(TreeNode* root,int &ans){
        if(root==nullptr)
            return {0,-10000,10000};
        int a,b,c;
        tuple<int,int,int> x=dfs(root->left,ans);
        tuple<int,int,int> y=dfs(root->right,ans);
        int a1=get<0>(x);int a2=get<0>(y);
        int b1=get<1>(x);int b2=get<1>(y);
        int c1=get<2>(x);int c2=get<2>(y);
        
        if(a1<0||a2<0){
            return {-1,0,0};
        }
        a=1+a1+a2;
        b=max(root->val,max(b1,b2));
        c=min(root->val,min(c1,c2));
        if(root->val<c2&&root->val>b1){
            ans=max(ans,a);
            return {a,b,c};
        }
        return{-1,0,0};
    }
    int largestBSTSubtree(TreeNode* root) {
        if(root==nullptr)
            return 0;
        int ans=1;
        tuple<int,int,int> z=dfs(root,ans);
        return ans;
    }
};
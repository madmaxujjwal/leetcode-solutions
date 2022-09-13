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
    vector<int> z;
    void dfs(TreeNode* root){
        if(root==nullptr)
            return;
        z.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int getMinimumDifference(TreeNode* root) {
        dfs(root);
        int n=z.size();
        sort(z.begin(),z.end());
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            ans=min(ans,z[i]-z[i-1]);
        }
        return ans;
    }
};
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
    int depth(TreeNode* root){
        if(root==nullptr)
            return 0;
        return 1+max(depth(root->left),depth(root->right));
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==nullptr)
            return {};
        int n=depth(root);
        queue<pair<TreeNode*,int>> q;
        vector<vector<int>> ans(n);
        q.push({root,0});
        while(q.size()>0){
            int level=q.front().second;
            TreeNode* value=q.front().first;
            q.pop();
            ans[level].push_back(value->val);
            if(value->left!=nullptr)
            q.push({value->left,level+1});
            if(value->right!=nullptr)
            q.push({value->right,level+1});
            
            
            
            
        }
        for(int i=0;i<n;i++){
            if(i%2!=0){
                reverse(ans[i].begin(),ans[i].end());
            }
        }
        return ans;
    }
};
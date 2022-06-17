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
    void dfs(TreeNode* root,priority_queue<pair<double,int>> &maxh,int k,double target){
        if(root==nullptr)
            return;
        double v=root->val;
        double z=abs((double)target-(double)v);
        maxh.push({z,v});
        if(maxh.size()>k)
            maxh.pop();
        dfs(root->left,maxh,k,target);
        dfs(root->right,maxh,k,target);
        
        
    }
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        priority_queue<pair<double,int>> maxh;
        vector<int> ans;
        dfs(root,maxh,k,target);
        while(maxh.size()!=0){
            ans.push_back(maxh.top().second);
            maxh.pop();
        }
        return ans;
        
    }
};
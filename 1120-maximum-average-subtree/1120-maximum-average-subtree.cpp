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
    pair<double,double> dfs(TreeNode* root,double &maxi){
        if(root==nullptr)
        {
            return {0,0};
        }
    
        pair<double,double> l= dfs(root->left,maxi);
        pair<double,double> r= dfs(root->right,maxi);
        double sum=l.first+r.first+root->val;
        double n=l.second+r.second+1;
        double avg=sum/n;
        if(maxi<avg){
            maxi=avg;
        }
        return {sum,n};
    }
    
    double maximumAverageSubtree(TreeNode* root) {
        double maxi=0.0000000;
        pair<double,double> x=dfs(root,maxi);
        return maxi;
    }
};
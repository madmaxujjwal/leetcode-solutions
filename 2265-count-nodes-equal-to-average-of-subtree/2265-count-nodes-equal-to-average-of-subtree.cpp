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
    pair<double,double> dfs(TreeNode* root,int &c){
        if(root==nullptr)
            return {0,0};
        pair<double,double> l=dfs(root->left,c);
        pair<double,double> r=dfs(root->right,c);
        double sum=root->val+l.first+r.first;
        double n=1+l.second+r.second;
        int avg=sum/n;
        if(avg==root->val){
            c++;
        }
        return {sum,n};
        
    }
    int averageOfSubtree(TreeNode* root) {
        int c=0;
        pair<double,double> x=dfs(root,c);
        return c;
    }
};
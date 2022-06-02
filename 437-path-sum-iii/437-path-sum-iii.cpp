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
    void dfs(TreeNode* root,int targetSum,unordered_map<int,int> &ht,long long int &c,long long int &sum){
        
        if(root==nullptr)
            return;
        sum=sum+root->val;
        c=c+ht[sum-targetSum];
        ht[sum]++;
        dfs(root->left,targetSum,ht,c,sum);
        dfs(root->right,targetSum,ht,c,sum);
        ht[sum]--;
        sum=sum-root->val;
        
        
    }
    int pathSum(TreeNode* root, int targetSum) {
        long long int c=0;
        long long int sum=0;
        unordered_map<int,int> ht;
        ht[0]=1;
        dfs(root,targetSum,ht,c,sum);
        return c;
    }
};
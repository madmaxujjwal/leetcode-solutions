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
    int dfs(TreeNode* root,unordered_map<int,int> &ht,int &maxi){
        if(root==nullptr)
            return 0;
        int z=root->val+dfs(root->left,ht,maxi)+dfs(root->right,ht,maxi);
       
        ht[z]++;
        if(maxi<ht[z]){
            maxi=ht[z];
        }
        return z;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> ans;
        unordered_map<int,int> ht;
        int maxi=-100000000000;
        int k=dfs(root,ht,maxi);
        for(auto it:ht){
            if(it.second==maxi){
                ans.push_back(it.first);
            }
        }
        return ans;
        
    }
};
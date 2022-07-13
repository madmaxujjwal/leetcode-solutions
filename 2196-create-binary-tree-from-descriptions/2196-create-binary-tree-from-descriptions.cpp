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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n=descriptions.size();
        unordered_map<int,TreeNode*> ht;
        unordered_map<int,int> ht1;
        
        for(int i=0;i<n;i++){
            int a=descriptions[i][0];
            int b=descriptions[i][1];
            ht1[b]++;
            if(ht.find(a)==ht.end()){
                TreeNode* x=new TreeNode(a);
                ht[a]=x;
            }
            if(ht.find(b)==ht.end()){
                TreeNode* y=new TreeNode(b);
                ht[b]=y;
            }
            
        }
        //return ht[2];
        int r;
        for(int i=0;i<n;i++){
             int a=descriptions[i][0];
             int b=descriptions[i][1];
             int c=descriptions[i][2];
            if(ht1[a]==0){
                r=a;
            }
            if(c==1){
                ht[a]->left=ht[b];
            }
            else
                ht[a]->right=ht[b];
        }
        return ht[r];
    }
};
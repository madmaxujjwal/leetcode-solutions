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
    set<TreeNode*> rec(int x){
        
            
       
       
        set<TreeNode*> ans;
        if(x==1){
             TreeNode* z=new TreeNode(0);
            ans.insert(z);
            return ans;
        }
        for(int i=1;i<=x-2;i=i+2){
            set<TreeNode*> l=rec(i);
            set<TreeNode*> r=rec(x-1-i);
            for(auto it:l){
                for(auto zt:r){
                    TreeNode* z=new TreeNode(0);
                    z->left=it;
                    z->right=zt;
                    ans.insert(z);
                }
                
            }
        }
        return ans;
    }
    
    vector<TreeNode*> allPossibleFBT(int n) {
        if(n%2==0)
            return {};
        vector<TreeNode*> ans;
        set<TreeNode*> g=rec(n);
        for(auto it:g){
            ans.push_back(it);
        }
        return ans;
    }
};
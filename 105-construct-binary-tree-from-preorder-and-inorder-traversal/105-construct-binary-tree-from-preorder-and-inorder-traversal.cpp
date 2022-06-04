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
    int search(vector<int> &inorder,int start,int end,int value){
        for(int i=start;i<=end;i++){
            if(inorder[i]==value){
                return i;
            }
        }
        return -1;
        
    }
    TreeNode* build(vector<int>& preorder,vector<int>& inorder,int start,int end,int &p){
           if(start>end)
               return nullptr;
        
             TreeNode* x=new TreeNode(preorder[p]);
        p++;
        if(start==end)
            return x;
        int pos=search(inorder,start,end,x->val);
       
        x->left=build(preorder,inorder,start,pos-1,p);
        
        x->right=build(preorder,inorder,pos+1,end,p);
        
        return x;
        
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int p=0;
        return build(preorder,inorder,0,inorder.size()-1,p);
    }
};
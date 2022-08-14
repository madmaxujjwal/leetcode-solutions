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
class BSTIterator {
public:
    vector<TreeNode*> z;
    int i;
    int n;
    void inorder(TreeNode* root){
        if(root==nullptr)
            return ;
        inorder(root->left);
        z.push_back(root);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
        n=z.size();
        i=-1;
    }
    
    bool hasNext() {
        return i<n-1;
    }
    
    int next() {
        return z[++i]->val;
    }
    
    bool hasPrev() {
        return i>0;
    }
    
    int prev() {
        return z[--i]->val;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * bool param_1 = obj->hasNext();
 * int param_2 = obj->next();
 * bool param_3 = obj->hasPrev();
 * int param_4 = obj->prev();
 */
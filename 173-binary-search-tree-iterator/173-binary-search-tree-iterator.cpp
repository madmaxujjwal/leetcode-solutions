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
    vector<TreeNode*> arr;
    int i;int n;
    void inorder(TreeNode* root){
        if(root==nullptr)
            return;
        inorder(root->left);
        arr.push_back(root);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        i=0;
        inorder(root);
        n=arr.size();
    }
    
    int next() {
        return arr[i++]->val;
    }
    
    bool hasNext() {
        return i<n;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
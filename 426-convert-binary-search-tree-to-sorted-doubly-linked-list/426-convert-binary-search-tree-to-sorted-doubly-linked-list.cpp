/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};
*/

class Solution {
public:
     vector<Node*> in;
    void dfs(Node* root){
        if(root==nullptr)
            return;
        dfs(root->left);
        in.push_back(root);
        dfs(root->right);
    }
    Node* treeToDoublyList(Node* root) {
       if(root==nullptr)
           return nullptr;
        dfs(root);
        int n=in.size();
        for(int i=0;i<n-1;i++){
            in[i]->right=in[i+1];
            in[i+1]->left=in[i];
        }
        in[n-1]->right=in[0];
        in[0]->left=in[n-1];
        return in[0];
    }
};
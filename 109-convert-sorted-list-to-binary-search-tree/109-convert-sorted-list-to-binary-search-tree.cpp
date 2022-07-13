/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    vector<int> in;
    int n;
    TreeNode* rec(int l,int r){
        if(l>r)
            return nullptr;
        if(l==r)
            return new TreeNode(in[r]);
        int m=(l+r)/2;
        TreeNode* x= new TreeNode(in[m]);
        x->left=rec(l,m-1);
        x->right=rec(m+1,r);
        return x;
    }
    
    TreeNode* sortedListToBST(ListNode* head) {
        
        ListNode* t=head;
        while(t!=nullptr){
            in.push_back(t->val);
            t=t->next;
        }
        n=in.size();
        return rec(0,n-1);
        
        
        
    }
};
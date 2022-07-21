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
    map<pair<ListNode*,TreeNode*>,bool> dp;
    ListNode* x;
    bool rec(ListNode* head,TreeNode* root){
        if(head==nullptr)
            return true;
        if(root==nullptr)
            return false;
        if(dp.find({head,root})!=dp.end())
            return dp[{head,root}];
    if(root->val==head->val){
        return dp[{head,root}]= rec(x,root->left)|rec(x,root->right)|rec(head->next,root->left)|rec(head->next,root->right);
    }
        else
        {
            return dp[{head,root}]=rec(x,root->left)|rec(x,root->right);
        }
    }
    
    bool isSubPath(ListNode* head, TreeNode* root) {x=head;
        return rec(head,root);
    }
};
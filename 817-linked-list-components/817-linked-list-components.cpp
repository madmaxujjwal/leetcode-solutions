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
class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        unordered_map<int,int> ht;
        int n=nums.size();
        for(int i=0;i<n;i++){
            ht[nums[i]]++;
        }
        ListNode* d=new ListNode(-1);
        d->next=head;
        head=d;
        ListNode* p=head;
        ListNode* x=head->next;int c=0;
        while(x!=nullptr){
            if(ht[x->val]>0&&ht[p->val]==0){
                c++;
            }
            x=x->next;
            p=p->next;
        }
        return c;
    }
};
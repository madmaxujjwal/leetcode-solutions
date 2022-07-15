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
    ListNode* oddEvenList(ListNode* head) {
        ListNode* x=head;
        int i=1;
        if(head==nullptr||head->next==nullptr){
            return head;
        }
        ListNode* z=head->next;
        while(x->next!=nullptr){
            
            ListNode* t=x->next;
            x->next=x->next->next;
            x=t;
            i++;
        }
        x=head;
        while(x->next!=nullptr){
            x=x->next;
        }
        x->next=z;
        
        return head;
    }
};
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==nullptr)
            return nullptr;
        ListNode* p=head;
        ListNode* x=head->next;bool v=false;
        if(x==nullptr)
            return p;
        while(x!=nullptr){
            if(p->val==x->val){
                p->next=x->next;
                v=true;
                
            }
            else{
                if(v==true){
                    p->val=INT_MIN;v=false;
                }
                p=p->next;
            }
            x=x->next;
            if(x==nullptr&&v){
                p->val=INT_MIN;
            }
        }
       // return head;
        ListNode* y=new ListNode(0);
        y->next=head;
        p=y;
        x=p->next;
        while(x!=nullptr){
            if(x->val==INT_MIN){
                p->next=x->next;
            }
            else{
                p=p->next;
            }
            x=x->next;
        }
        
        
        return y->next;
    }
};
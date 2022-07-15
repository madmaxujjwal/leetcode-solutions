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
    ListNode* partition(ListNode* head, int x) {
        if(head==nullptr||(head->next==nullptr))
            return head;
        ListNode* pa=nullptr;bool a=false;
        ListNode* pb=nullptr;bool b=false;ListNode* h=nullptr;ListNode* t=nullptr;
        ListNode* y=head;
        while(y!=nullptr){
            if(y->val<x){
                if(a){
                    pa->next=y;
                    pa=y;
                }
                else{
                    pa=y;
                    h=pa;
                    a=true;
                }
            }
            else{
                if(b){
                    pb->next=y;
                    pb=y;
                }
                else{
                    pb=y;
                    t=pb;
                    b=true;
                }
            }
            y=y->next;
        }
        
        if(pb!=nullptr)
       pb->next=nullptr;
       if(pa!=nullptr)
        pa->next=t;
        if(pa==nullptr)
            return t;
        return h;
    }
};
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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* a=nullptr;ListNode* t;
        ListNode* b=nullptr;
        ListNode* c=nullptr;
        ListNode* d=nullptr;
        ListNode* x=head;
        ListNode* p=head;
        int i=1;
        while(x!=nullptr){
        
            if(i==(left-1)){
                a=x;
            }
            if(i==(left)){
                b=x;
            }
            if(i==(right)){
                c=x;
            }
            if(i==(right+1)){
                d=x;
            }
            if(i==1){
                i++;
                x=x->next;
                continue;
            }
            if(i>left&&i<=right){
                t=x->next;
                x->next=p;
                p=x;
                x=t;
            }
            else{
                x=x->next;
                p=p->next;
            }
            i++;
        }
        if(a==nullptr){
            head=c;
        }
        if(a!=nullptr)
        {a->next=c;
         
        }
       // if(d!=nullptr)
        b->next=d;
        
        
        return head;
    }
};
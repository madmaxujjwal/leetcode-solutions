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
    int n;
    ListNode* h;
    Solution(ListNode* head) {
        h=head;
        ListNode* ptr=head;int c=0;
        while(ptr!=nullptr){
            c++;
            ptr=ptr->next;
        }
        n=c;
    }
    
    int getRandom() {
        int index=rand()%n;
        ListNode* ptr=h;int c=0;
        while(ptr!=nullptr){
            if(c==index){
                return ptr->val;
            }
            c++;
            ptr=ptr->next;
        }
        return -1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
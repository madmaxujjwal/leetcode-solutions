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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans(k);
        ListNode* d=new ListNode(-1);
        d->next=head;
        ListNode* x=head;
        int n=0;
        while(x!=nullptr){
            n++;
            x=x->next;
        }
        int a;int b;int A;int B;
        if(n%k==0){
            A=0;
            B=n/k;
            a=0;
            b=k;
        }
        else{
         A=ceil((double)n/k);
         B=n/k;
         a=(n-k*B)/(A-B);
         b=k-a;   
        }
    //    return {new ListNode(A),new ListNode(B),new ListNode(a),new ListNode(b)};
        vector<int> index;int in=0;
        for(int i=0;i<a;i++){
            index.push_back(in);
            in=in+A;
        }
        
        for(int i=0;i<b;i++){
            index.push_back(in);
            in+=B;
        }
    
        x=head;int i=0;int j=0;ListNode* p=d;
        //return {new ListNode(index[0]),new ListNode(index[1])};
        while(x!=nullptr){
            if(j==index.size()){
                break;
            }
            if(index[j]==i){
                p->next=nullptr;
                ans[j]=x;
                j++;
                
                
            }
            i++;
            p=x;
            x=x->next;
        }
        return ans;
    }
};
/**
 * Definition for polynomial singly-linked list.
 * struct PolyNode {
 *     int coefficient, power;
 *     PolyNode *next;
 *     PolyNode(): coefficient(0), power(0), next(nullptr) {};
 *     PolyNode(int x, int y): coefficient(x), power(y), next(nullptr) {};
 *     PolyNode(int x, int y, PolyNode* next): coefficient(x), power(y), next(next) {};
 * };
 */

class Solution {
public:
    PolyNode* addPoly(PolyNode* poly1, PolyNode* poly2) {
        
        PolyNode* a=poly1;
        PolyNode* b=poly2;
        PolyNode* h=new PolyNode(-1,-1);
        PolyNode* head=h;
        while((a!=nullptr)||(b!=nullptr)){
            if(a==nullptr){
                int c=b->coefficient;
                int p=b->power;
                
                PolyNode* x=new PolyNode(c,p);
                h->next=x;
                h=x;
                b=b->next;
            }
            else if(b==nullptr){
                int c=a->coefficient;
                int p=a->power;
                PolyNode* x=new PolyNode(c,p);
                h->next=x;
                h=x;
                a=a->next;
            }
            else if(a->power==b->power){
                
                int c=a->coefficient+b->coefficient;
                int p=a->power;
                if(c!=0){
                PolyNode* x=new PolyNode(c,p);
                h->next=x;
                h=x;
                }
                a=a->next;
                b=b->next;
            }
            else if(a->power>b->power){
                int c=a->coefficient;
                int p=a->power;
                PolyNode* x=new PolyNode(c,p);
                h->next=x;
                h=x;
                a=a->next;
            }
            else{
                int c=b->coefficient;
                int p=b->power;
                PolyNode* x=new PolyNode(c,p);
                h->next=x;
                h=x;
                b=b->next;
                
            }
        }
        return head->next;
    }
};
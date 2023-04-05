

class node
{
    public:
    node* next[26];
    int val;
    bool endswith;
    node(){
        for(int i=0;i<26;i++){
            next[i]=NULL;
        }
        endswith=false;
        val=0;
    }
    
};
class tries
{
    public:
    node* root;
    
    tries(){
        root=new node();
    }
    
    void insert(string x){
        int n=x.size();
        node* r=root;
        for(int i=0;i<n;i++){
            if(r->next[x[i]-'a']==NULL){
                r->next[x[i]-'a']=new node();
            }
            r=r->next[x[i]-'a'];
            r->val=r->val+1;
        }
        
    }
    int present(string x){
        int n=x.size();int ans=0;
        node* r=root;
        for(int i=0;i<n;i++){
            r=r->next[x[i]-'a'];
            ans=ans+r->val;
        }
        return ans;
    }
};
class Solution {
public:
    vector<int> sumPrefixScores(vector<string>& words) {
        tries* t=new tries();int n=words.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            t->insert(words[i]);
        }
        
        for(int i=0;i<n;i++){
            ans[i]=t->present(words[i]);
        }
        return ans;
    }
};
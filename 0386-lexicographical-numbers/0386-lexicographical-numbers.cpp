
class node
{
    public:
    node* next[10];
    bool endwith;
    node(){
        
        for(int i=0;i<10;i++){
            next[i]=NULL;
            
        }
        endwith=false;
    }
};
class tries{
    public:
    node* root;
    
    tries(){
        root=new node();
    }
    void insert(string x){
        int n=x.size();
        node* r=root;
        for(int i=0;i<n;i++){
            if(r->next[x[i]-'0']==NULL){
                r->next[x[i]-'0']=new node();
            }
            r=r->next[x[i]-'0'];
        }
        r->endwith=true;
    }
    bool present(string x){
        int n=x.size();
        node* r=root;
        for(int i=0;i<n;i++){
            if(r->next[x[i]-'0']==NULL)return false;
            r=r->next[x[i]-'0'];
        }
        if(r->endwith==true)return true;
        return false;
    }
    void back(node* r,string x,vector<int> &ans){
          if(r->endwith==true){
                    ans.push_back(stoi(x));
                }
        for(int i=0;i<10;i++){
            if(r->next[i]!=NULL){
              
                back(r->next[i],x+char(i+48),ans);
            }
            
        }
        return ;
    }
};

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        tries* t=new tries();
        for(int i=1;i<=n;i++){
            t->insert(to_string(i));
        }
        vector<int> ans;
        t->back(t->root,"",ans);
        return ans;
    }
};
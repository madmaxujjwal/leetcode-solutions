class node
    { 
    public:
    node* next[26]; 
        bool endwith;
     node(){
         
         for(int i=0;i<26;i++){
             next[i]=NULL;
             
         }
         endwith=false;
     }
    };
class Trie {
public:
    node* r;
    Trie() {
        r=new node();
    }
    
    void insert(string word) {
        int n=word.size();
        node* root=r;
        for(int i=0;i<n;i++){
            
            if(root->next[word[i]-'a']==NULL){
                root->next[word[i]-'a']=new node();
            }
            root=root->next[word[i]-'a'];
            
        }
        root->endwith=true;
    }
    
    bool search(string word) {
        int n=word.size();
        node* root=r;
        for(int i=0;i<n;i++){
            if(root->next[word[i]-'a']==NULL)return false;
            root=root->next[word[i]-'a'];
        }
        if(root->endwith==true)return true;
        return false;
        
    }
    
    bool startsWith(string prefix) {
        int n=prefix.size();
        node* root=r;
        for(int i=0;i<n;i++){
            if(root->next[prefix[i]-'a']==NULL)return false;
            root=root->next[prefix[i]-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
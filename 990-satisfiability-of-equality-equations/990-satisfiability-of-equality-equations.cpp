class Solution {
public:
    unordered_map<char,char> parent;
    unordered_map<char,int> size;
    void make_set(char a){
        parent[a]=a;
        size[a]=1;
    }
    char find_set(char a){
        if(a==parent[a])
            return a;
        return parent[a]=find_set(parent[a]);
    }
    void make_union(char a,char b){
        a=find_set(a);
        b=find_set(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
                
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        for(int i=0;i<n;i++){
            make_set(equations[i][0]);
            make_set(equations[i][3]);
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                char ch1=equations[i][0];
                char ch2=equations[i][3];
                if(parent[ch1]!=parent[ch2]){
                    make_union(ch1,ch2);
                }
            }
            else{
                 char ch1=equations[i][0];
                char ch2=equations[i][3];
                if(parent[ch1]==parent[ch2]){
                    return false;
                }
                
            }
        }
        for(int i=0;i<n;i++){
            if(equations[i][1]=='='){
                char ch1=equations[i][0];
                char ch2=equations[i][3];
                if(parent[ch1]!=parent[ch2]){
                    make_union(ch1,ch2);
                }
            }
            else{
                 char ch1=equations[i][0];
                char ch2=equations[i][3];
                if(parent[ch1]==parent[ch2]){
                    return false;
                }
                
            }
        }
        
        return true;
    }
};
class Solution {
public:
   
    vector<int> parent;
    vector<int> size;
    void make_set(int a){
        parent[a]=a;
        size[a]=1;
    }
    int find_set(int a){
        if(a==parent[a])
            return a;
        return parent[a]=find_set(parent[a]);
    }
    void make_union(int a,int b){
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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int a=0;
        unordered_map<int,int> ht;
        parent.resize(n);
        size.resize(n);
        for(int i=0;i<n;i++){
            make_set(i);
        }
        for(int i=0;i<connections.size();i++){
            int x=find_set(connections[i][0]);
            int y=find_set(connections[i][1]);
            if(x==y){
                a++;
            }
            else{
                make_union(x,y);
            }
           
            
        }
         for(int i=0;i<connections.size();i++){
            int x=find_set(connections[i][0]);
            int y=find_set(connections[i][1]);
            if(x==y){
                int g=0;
            }
            else{
                make_union(x,y);
            }
           
            
        }
        
        for(int i=0;i<n;i++){
            ht[parent[i]]++;
        }
       
        int b=ht.size()-1;
       
        if(a>=b){
            return min(a,b);
        }
        return -1;
    }
};
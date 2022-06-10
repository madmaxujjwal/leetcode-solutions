class Solution {
public:
    int n;
    vector<int> len;
    vector<bool> visited;
    vector<int> size;
    vector<int> parent;
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
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
    bool dfs(vector<vector<int>> graph,int i,int d,int p,bool &c){
        visited[i]=true;
       if(c)
           return true;
        if(p!=-1){
        if(find_set(i)==find_set(p)){
           if(abs(len[i]-len[p])%2==0){
               c=true;
            return true;
           }
            return false;
        }
        else{
            make_union(i,p);
        }
            
        }
        len[i]=d;
        bool z=false;
        for(auto it:graph[i]){
           if(it!=p)
            z= z| dfs(graph,it,d+1,i,c);
        }
        return z;
    
    }
    bool isBipartite(vector<vector<int>>& graph) {
        n=graph.size();
        visited.resize(n);
        size.resize(n);
        parent.resize(n);
        len.resize(n);bool c=false;
        for(int i=0;i<n;i++)
            make_set(i);
        for(int i=0;i<n;i++){
            if(visited[i]==true){
                continue;
            }
           bool k= dfs(graph,i,0,-1,c);
            if(k==true){
                return false;
            }
        }
        return true;
    }

};
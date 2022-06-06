class Solution {
public:
    void dfs(int i,int p, vector<int> adj[],vector<bool> &visited,bool &k){
        if(visited[i]==true)
            {k=false;return;
        }
        visited[i]=true;bool z=true;
        for(int j=0;j<adj[i].size();j++){
            if(adj[i][j]!=p){
              dfs(adj[i][j],i,adj,visited,k);
                if(k==false)
                    return;
                
            }
        }
      
    }
    
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
             adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n,false);bool k=true;
        dfs(0,-1,adj,visited,k);
        for(int i=0;i<n;i++){
            k=k&visited[i];
        }
        return k;
        
    }
};
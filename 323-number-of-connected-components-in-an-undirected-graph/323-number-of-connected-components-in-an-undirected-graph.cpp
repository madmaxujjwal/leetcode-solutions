class Solution {
public:
    void dfs(int x,vector<int> adj[],vector<bool> &visited){
        visited[x]=true;
        for(int i=0;i<adj[x].size();i++){
            if(visited[adj[x][i]]!=true){
               
                dfs(adj[x][i],adj,visited);
            }
        }
    }
    int countComponents(int n, vector<vector<int>>& edges) {int c=0;
        
        vector<int> adj[n];
        int z=edges.size();
        for(int i=0;i<z;i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }vector<bool> visited(n,false);
        for(int i=0;i<n;i++){
            if(visited[i]==false){c++;
                
                
                dfs(i,adj,visited);
            }
        }return c;
    }
};
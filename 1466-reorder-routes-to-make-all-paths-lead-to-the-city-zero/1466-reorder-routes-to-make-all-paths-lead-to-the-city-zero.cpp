class Solution {
public:
    vector<bool> visited;
    vector<vector<pair<int,int>>> adj;
    void dfs(int i,int &c){
        visited[i]=true;
        for(auto it:adj[i]){
            if(visited[it.first]==true)
                continue;
            if(it.second==-1){
                c++;
                dfs(it.first,c);
            }else{
                 dfs(it.first,c);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        visited.resize(n);
        for(int i=0;i<n;i++)
            visited[i]=false;
        adj.resize(n);
        for(int i=0;i<connections.size();i++){
            adj[connections[i][0]].push_back({connections[i][1],-1});
            adj[connections[i][1]].push_back({connections[i][0],1});
        }
        int c=0;
        dfs(0,c);
        return c;
    }
};
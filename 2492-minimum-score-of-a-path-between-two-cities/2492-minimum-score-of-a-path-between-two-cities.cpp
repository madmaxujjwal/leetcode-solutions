class Solution {
public:
    
    int dfs(int i,vector<bool> &vis,vector<vector<pair<int,int>>> &adj){
        vis[i]=true;
        int ans=INT_MAX;
        for(auto it:adj[i]){
            ans=min(ans,it.second);
            if(vis[it.first]==false){
            ans=min({ans,it.second,dfs(it.first,vis,adj)});
                
            }
            
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool> vis(n,false);
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            
            adj[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});
            
        }
        return dfs(0,vis,adj);
    }
};
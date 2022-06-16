class Solution {
public:
    
    int dfs(int i,vector<int>& informTime,vector<int> adj[]){
        int res=informTime[i];
        int z=0;
        for(auto it:adj[i]){
            z=max(z,dfs(it,informTime,adj));
        }
        return res+z;
    }
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        for(int i=0;i<n;i++){
            if(i!=headID)
            adj[manager[i]].push_back(i);
            
        }
        return dfs(headID,informTime,adj);
        
    }
};
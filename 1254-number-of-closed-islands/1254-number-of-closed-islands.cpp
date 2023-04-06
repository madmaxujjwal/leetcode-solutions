class Solution {
public:
    vector<vector<int>> g;
    int m;
    int n;
    bool dfs(int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true; bool ans=true;
        if(i==0||i==m-1||j==0||j==n-1){
            ans=false;
        }
        
       
        if(i-1>=0&&vis[i-1][j]==false&&g[i-1][j]==0)
            ans=ans&dfs(i-1,j,vis);
        if(i+1<m&&vis[i+1][j]==false&&g[i+1][j]==0)
            ans=ans&dfs(i+1,j,vis);
        if(j-1>=0&&vis[i][j-1]==false&&g[i][j-1]==0)
            ans=ans&dfs(i,j-1,vis);
        if(j+1<n&&vis[i][j+1]==false&&g[i][j+1]==0)
            ans=ans&dfs(i,j+1,vis);
        
        return ans;
        
        
    }
    int closedIsland(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        g=grid;
        int ans=0;
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                if(g[i][j]==0&&vis[i][j]==false){
                    if(dfs(i,j,vis)==true){
                        ans++;
                    }
                }
            }
            
            
        }
        return ans;
    }
};
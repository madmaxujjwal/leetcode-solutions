class Solution {
public:
    int m;
    int n;
    vector<vector<int>> g;
    bool dfs(int i,int j,vector<vector<bool>> &vis){
        vis[i][j]=true;
        bool z=true;
        if(i==0||i==m-1||j==0||j==n-1){
            z=false;
        }
        bool a=true;bool b=true;bool c=true;bool d=true;
        if(i>0&&vis[i-1][j]==false&&g[i-1][j]==0)
           a= dfs(i-1,j,vis);
        if(i<m-1&&vis[i+1][j]==false&&g[i+1][j]==0)
           b= dfs(i+1,j,vis);
        if(j>0&&vis[i][j-1]==false&&g[i][j-1]==0)
            c=dfs(i,j-1,vis);
        if(j<n-1&&vis[i][j+1]==false&&g[i][j+1]==0)
            d=dfs(i,j+1,vis);
        
        return z&&a&&b&&c&&d;
    }
    int closedIsland(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        g=grid;
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false&&g[i][j]==0){
                    if(dfs(i,j,vis))
                        c++;
                }
            }
        }
        return c;
    }
};
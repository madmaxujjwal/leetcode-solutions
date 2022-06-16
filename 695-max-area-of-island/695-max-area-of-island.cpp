class Solution {
public:
    
    int dfs(vector<vector<int>>& grid,vector<vector<bool>> &visited,int i,int j,int m,int n){
        visited[i][j]=true;
        int c=1;
        if((i-1)>=0&&grid[i-1][j]==1&&visited[i-1][j]==false){
        c+=dfs(grid,visited,i-1,j,m,n);
        }
        if((i+1)<m&&grid[i+1][j]==1&&visited[i+1][j]==false){
        c+=dfs(grid,visited,i+1,j,m,n);
        }
        if((j-1)>=0&&grid[i][j-1]==1&&visited[i][j-1]==false){
        c+=dfs(grid,visited,i,j-1,m,n);
        }
        if((j+1)<n&&grid[i][j+1]==1&&visited[i][j+1]==false){
        c+=dfs(grid,visited,i,j+1,m,n);
        }
     return c;   
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==false){
                    ans=max(ans,dfs(grid,visited,i,j,m,n));
                }
            }
        }
        return ans;
    }
};
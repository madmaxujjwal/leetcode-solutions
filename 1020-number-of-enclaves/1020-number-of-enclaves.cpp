class Solution {
public:
    bool visited[501][501];vector<vector<int>> g;
    int m;
    int n;
    int dfs(int i,int j){int v=1;
        visited[i][j]=true;
        if(i==0||i==m-1||j==0||j==n-1)
            v= -1000000;
        int a=0;int b=0;int c=0;int d=0;
        if(i>0&&visited[i-1][j]==false&&g[i-1][j]==1){
            visited[i-1][j]==true;
            a=dfs(i-1,j);
        }
        if(j>0&&visited[i][j-1]==false&&g[i][j-1]==1){
            visited[i][j-1]==true;
            b=dfs(i,j-1);
        }
        if(i<m-1&&visited[i+1][j]==false&&g[i+1][j]==1){
            visited[i+1][j]==true;
            c=dfs(i+1,j);
        }
        if(j<n-1&&visited[i][j+1]==false&&g[i][j+1]==1){
            visited[i][j+1]==true;
            d=dfs(i,j+1);
        }
        return v+a+b+c+d;
    }
    int numEnclaves(vector<vector<int>>& grid) {
         m=grid.size();
         n=grid[0].size();g=grid;
        memset(visited,false,sizeof(visited));
        int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1&&visited[i][j]==false){
                    
                    ans=ans+max(0,dfs(i,j));
                }
            }
        }
        return ans;
    }
};
class Solution {
public:
    bool dfs(vector<vector<int>>& grid,int i,int j,int m,int n){
        if(((i-1)>=0)&&grid[i-1][j]==1){
            return true;
        }
        if(((i+1)<m)&&grid[i+1][j]==1){
            return true;
        }
        if(((j-1)>=0)&&grid[i][j-1]==1){
            return true;
        }
        if(((j+1)<n)&&grid[i][j+1]==1){
            return true;
        }
        return false;
    }
    int countServers(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        unordered_map<int,int> row;
        unordered_map<int,int> column;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    row[i]++;
                    column[j]++;
                }
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {
                    if(row[i]>1||column[j]>1)
                        c++;
                }
            }
        }
        return c;
    }
};
class Solution {
public:
    int getFood(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]=='*'){
                    q.push({{i,j},0});
                    break;
                }
            }
        }
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            
            q.pop();
             if((x-1)>=0&&(grid[x-1][y]=='#')){
                return d+1;
            }
            if((y-1)>=0&&(grid[x][y-1]=='#')){
                return d+1;
            }
            if((x+1)<=m-1&&(grid[x+1][y]=='#')){
                return d+1;
            }
            if((y+1)<=n-1&&(grid[x][y+1]=='#')){
                return d+1;
            }
            
            
            if((x-1)>=0&&(grid[x-1][y]=='O')){
                grid[x-1][y]='X';
                q.push({{x-1,y},d+1});
            }
            if((y-1)>=0&&(grid[x][y-1]=='O')){
                grid[x][y-1]='X';
                q.push({{x,y-1},d+1});
            }
            if((x+1)<=m-1&&(grid[x+1][y]=='O')){
                grid[x+1][y]='X';
                q.push({{x+1,y},d+1});
            }
            if((y+1)<=n-1&&(grid[x][y+1]=='O')){
                grid[x][y+1]='X';
                q.push({{x,y+1},d+1});
            }
            
        }
        return -1;
    }
};
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                             }
                     }}
        int t=0;
        
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int time=q.front().second;
            q.pop();
            t=max(t,time);
            
            grid[x][y]=2;
            if(x>0&&grid[x-1][y]==1){
                q.push({{x-1,y},time+1});
                grid[x-1][y]=2;
            }
            if(y>0&&grid[x][y-1]==1){
                q.push({{x,y-1},time+1});
                grid[x][y-1]=2;
            }
            if(x<m-1&&grid[x+1][y]==1){
                q.push({{x+1,y},time+1});
                grid[x+1][y]=2;
            }
            if(y<n-1&&grid[x][y+1]==1){
                q.push({{x,y+1},time+1});
                grid[x][y+1]=2;
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1)
                {return -1;}
            }
        }
     
        return t;
    }
};
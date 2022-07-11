class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>> q;
        if(grid[0][0]==1||grid[n-1][n-1]==1)
            return -1;
        q.push({{0,0},1});
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            grid[x][y]=1;
            q.pop();
            if(x==y&&x==n-1){
                return d;
            }if(x-1>=0&&grid[x-1][y]==0)
            {q.push({{x-1,y},d+1});
            grid[x-1][y]=1;
            }
            if(x+1<n&&grid[x+1][y]==0)
            {q.push({{x+1,y},d+1});
            grid[x+1][y]=1;
            }
            if(y-1>=0&&grid[x][y-1]==0)
            {q.push({{x,y-1},d+1});
            grid[x][y-1]=1;
            }
            if(y+1<n&&grid[x][y+1]==0)
            {q.push({{x,y+1},d+1});
            grid[x][y+1]=1;
            }
            if(x-1>=0&&y-1>=0&&grid[x-1][y-1]==0)
            {q.push({{x-1,y-1},d+1});
            grid[x-1][y-1]=1;
            }
             if(x-1>=0&&y+1<n&&grid[x-1][y+1]==0)
             {q.push({{x-1,y+1},d+1});
             grid[x-1][y+1]=1;
             }
            if(x+1<n&&y-1>=0&&grid[x+1][y-1]==0)
            {q.push({{x+1,y-1},d+1});
            grid[x+1][y-1]=1;
            }
            if(x+1<n&&y+1<n&&grid[x+1][y+1]==0)
            { q.push({{x+1,y+1},d+1});
            grid[x+1][y+1]=1;
            }
        }
        return -1;
    }
};
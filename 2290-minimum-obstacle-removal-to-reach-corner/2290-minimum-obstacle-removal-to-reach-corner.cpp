class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        dis[0][0]=1;
        pq.push({0,{0,0}});
        
        while(pq.size()>0){
            
            
            int d=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            pq.pop();
            vis[x][y]=true;
            if(x-1>=0&&vis[x-1][y]==false){
                if(d+grid[x-1][y]<dis[x-1][y]){
                    dis[x-1][y]=d+grid[x-1][y];
                    pq.push({d+grid[x-1][y],{x-1,y}});
                }
            }
            if(x+1<m&&vis[x+1][y]==false){
                if(d+grid[x+1][y]<dis[x+1][y]){
                    dis[x+1][y]=d+grid[x+1][y];
                    pq.push({d+grid[x+1][y],{x+1,y}});
                }
            }
            if(y-1>=0&&vis[x][y-1]==false){
                if(d+grid[x][y-1]<dis[x][y-1]){
                    dis[x][y-1]=d+grid[x][y-1];
                    pq.push({d+grid[x][y-1],{x,y-1}});
                }
            }
            if(y+1<n&&vis[x][y+1]==false){
                if(d+grid[x][y+1]<dis[x][y+1]){
                    dis[x][y+1]=d+grid[x][y+1];
                    pq.push({d+grid[x][y+1],{x,y+1}});
                }
            }
        }
        return dis[m-1][n-1];
    }
};
class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][1]>1&&grid[1][0]>1)return -1;
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        while(pq.size()>0){
           int x=pq.top().second.first;
            int y=pq.top().second.second;
            int d=pq.top().first;
            pq.pop();
             vis[x][y]=true;
            if(d<dis[x][y]){
                dis[x][y]=d;
                if(x-1>=0&&vis[x-1][y]==false){
                    int z=(d+1)-grid[x-1][y];
                    if(z>=0)
                    pq.push({d+1,{x-1,y}});
                    else{
                        if(z%2==0){
                            pq.push({grid[x-1][y],{x-1,y}});
                        }
                        else{
                            pq.push({grid[x-1][y]+1,{x-1,y}});
                        }
                    }
                }
                if(x+1<m&&vis[x+1][y]==false){
                    int z=(d+1)-grid[x+1][y];
                    if(z>=0)
                    pq.push({d+1,{x+1,y}});
                    else{
                        if(z%2==0){
                            pq.push({grid[x+1][y],{x+1,y}});
                        }
                        else{
                            pq.push({grid[x+1][y]+1,{x+1,y}});
                        }
                    }
                }
                if(y-1>=0&&vis[x][y-1]==false){
                    int z=(d+1)-grid[x][y-1];
                    if(z>=0)
                    pq.push({d+1,{x,y-1}});
                    else{
                        if(z%2==0){
                            pq.push({grid[x][y-1],{x,y-1}});
                        }
                        else{
                            pq.push({grid[x][y-1]+1,{x,y-1}});
                        }
                    }
                }
                if(y+1<n&&vis[x][y+1]==false){
                     int z=(d+1)-grid[x][y+1];
                    if(z>=0)
                    pq.push({d+1,{x,y+1}});
                    else{
                        if(z%2==0){
                            pq.push({grid[x][y+1],{x,y+1}});
                        }
                        else{
                            pq.push({grid[x][y+1]+1,{x,y+1}});
                        }
                    }
                }
            }
        }
        // if(dis[m-1][n-1]==INT_MAX)return -1;
        return dis[m-1][n-1];
    }
};
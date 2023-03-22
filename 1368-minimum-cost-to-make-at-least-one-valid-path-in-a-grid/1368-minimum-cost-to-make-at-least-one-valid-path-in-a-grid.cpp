class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
       if(m*n==1)return 0;
        priority_queue<pair<int,pair<int,int>>,vector< pair<int,pair<int,int>>>,greater< pair<int,pair<int,int>>>> pq;
        
        pq.push({0,{0,0}});
        while(pq.size()>0){
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            int d=pq.top().first;
            vis[x][y]=true;
            pq.pop();
            if(x-1>=0&&vis[x-1][y]==false){
                int c=d;
                if(grid[x][y]!=4){
                    c++;
                }
                if(dis[x-1][y]>c){
                    dis[x-1][y]=c;
                    pq.push({c,{x-1,y}});
                    
                }
            }
            if(x+1<m&&vis[x+1][y]==false){
                int c=d;
                if(grid[x][y]!=3){
                    c++;
                }
                if(dis[x+1][y]>c){
                    dis[x+1][y]=c;
                    pq.push({c,{x+1,y}});
                    
                }
            }
            if(y+1<n&&vis[x][y+1]==false){
                int c=d;
                if(grid[x][y]!=1){
                    c++;
                }
                if(dis[x][y+1]>c){
                    dis[x][y+1]=c;
                    pq.push({c,{x,y+1}});
                    
                }
            }
            if(y-1>=0&&vis[x][y-1]==false){
                int c=d;
                if(grid[x][y]!=2){
                    c++;
                }
                if(dis[x][y-1]>c){
                    dis[x][y-1]=c;
                    pq.push({c,{x,y-1}});
                    
                }
            }
        }
        return dis[m-1][n-1];
    }
};
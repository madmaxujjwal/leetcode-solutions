class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        bool vis[m][n][k+1];
        int dis[m][n][k+1];
        if(m*n==1)return 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                for(int s=0;s<=k;s++){
                    vis[i][j][s]=false;
                    dis[i][j][s]=INT_MAX;
                }
                
                
            }
        }
        
        priority_queue< pair<int,pair<int,pair<int,int>>>,vector< pair<int,pair<int,pair<int,int>>>>,greater< pair<int,pair<int,pair<int,int>>>>> pq;
        pq.push({0,{0,{0,0}}});
        
        while(pq.size()>0){
            
            
            int d=pq.top().first;
            int z=pq.top().second.first;
            int x=pq.top().second.second.first;
            int y=pq.top().second.second.second;
            pq.pop();
            vis[x][y][z]=true;
           
            if(x-1>=0&&((grid[x-1][y]==1&&z+1<=k&&vis[x-1][y][z+1]==false)||(grid[x-1][y]==0&&vis[x-1][y][z]==false))){
                if(grid[x-1][y]==0&&d+1<dis[x-1][y][z]){
                    dis[x-1][y][z]=d+1;
                    pq.push({d+1,{z,{x-1,y}}});
                }
                if(grid[x-1][y]==1&&d+1<dis[x-1][y][z+1]){
                    dis[x-1][y][z+1]=d+1;
                    pq.push({d+1,{z+1,{x-1,y}}});
                }
                
                
            }
            if(x+1<m&&((grid[x+1][y]==1&&z+1<=k&&vis[x+1][y][z+1]==false)||(grid[x+1][y]==0&&vis[x+1][y][z]==false))){
                if(grid[x+1][y]==0&&d+1<dis[x+1][y][z]){
                    dis[x+1][y][z]=d+1;
                    pq.push({d+1,{z,{x+1,y}}});
                }
                if(grid[x+1][y]==1&&d+1<dis[x+1][y][z+1]){
                    dis[x+1][y][z+1]=d+1;
                    pq.push({d+1,{z+1,{x+1,y}}});
                }
                
                
            }
             if(y-1>=0&&((grid[x][y-1]==1&&z+1<=k&&vis[x][y-1][z+1]==false)||(grid[x][y-1]==0&&vis[x][y-1][z]==false))){
                if(grid[x][y-1]==0&&d+1<dis[x][y-1][z]){
                    dis[x][y-1][z]=d+1;
                    pq.push({d+1,{z,{x,y-1}}});
                }
                if(grid[x][y-1]==1&&d+1<dis[x][y-1][z+1]){
                    dis[x][y-1][z+1]=d+1;
                    pq.push({d+1,{z+1,{x,y-1}}});
                }
                
                
            }
           if(y+1<n&&((grid[x][y+1]==1&&z+1<=k&&vis[x][y+1][z+1]==false)||(grid[x][y+1]==0&&vis[x][y+1][z]==false))){
                if(grid[x][y+1]==0&&d+1<dis[x][y+1][z]){
                    dis[x][y+1][z]=d+1;
                    pq.push({d+1,{z,{x,y+1}}});
                }
                if(grid[x][y+1]==1&&d+1<dis[x][y+1][z+1]){
                    dis[x][y+1][z+1]=d+1;
                    pq.push({d+1,{z+1,{x,y+1}}});
                }
                
                
            }
        }
        
        int ans=INT_MAX;
        for(int i=0;i<=k;i++){
            ans=min(ans,dis[m-1][n-1][i]);
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};
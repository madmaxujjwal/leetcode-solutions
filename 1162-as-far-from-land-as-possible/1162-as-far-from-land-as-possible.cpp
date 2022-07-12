class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                }
            }
        }
        if(q.size()==n*n||q.size()==0)
            return -1;
           
        int ans=-1;
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            q.pop();
            ans=max(ans,d);
            if((x-1)>=0&&grid[x-1][y]==0){
                grid[x-1][y]=1;
                q.push({{x-1,y},d+1});
            }
             if((y-1)>=0&&grid[x][y-1]==0){
                 grid[x][y-1]=1;
                q.push({{x,y-1},d+1});
            }
             if((x+1)<=n-1&&grid[x+1][y]==0){
                 grid[x+1][y]=1;
                q.push({{x+1,y},d+1});
            }
             if((y+1<=n-1)&&grid[x][y+1]==0){
                 grid[x][y+1]=1;
                q.push({{x,y+1},d+1});
            }
            
            
            
        }
        return ans;
    }
};
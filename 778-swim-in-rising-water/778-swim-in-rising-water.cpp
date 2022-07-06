class Solution {
public:
    
    int swimInWater(vector<vector<int>>& grid) {
        int n=grid.size();
        vector<vector<int>> visited(n,vector<int>(n,false));
        int ans=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
        q.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        while(q.size()>0){
             ans=max(ans,q.top().first);
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==n-1&&y==n-1){
               break;
            }
            if(x>0&&visited[x-1][y]==false){
                visited[x-1][y]=true;
                q.push({grid[x-1][y],{x-1,y}});
            }
            if(y>0&&visited[x][y-1]==false){
                visited[x][y-1]=true;
                q.push({grid[x][y-1],{x,y-1}});
            }
            if(x<n-1&&visited[x+1][y]==false){
                visited[x+1][y]=true;
                q.push({grid[x+1][y],{x+1,y}});
            }
            if(y<n-1&&visited[x][y+1]==false){
                visited[x][y+1]=true;
                q.push({grid[x][y+1],{x,y+1}});
            }
        }
        return ans;
    }
};
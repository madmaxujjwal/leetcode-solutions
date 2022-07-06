class Solution {
public:
    int maximumMinimumPath(vector<vector<int>>& grid) {
        int m=grid.size();int n=grid[0].size();
        int ans=INT_MAX;
        priority_queue<pair<int,pair<int,int>>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        q.push({grid[0][0],{0,0}});
        visited[0][0]=true;
        while(q.size()>0){
            ans=min(ans,q.top().first);
            int x=q.top().second.first;
            int y=q.top().second.second;
            q.pop();
            if(x==m-1&&y==n-1){
                return ans;
            }
            if(x>0&&visited[x-1][y]==false){
                visited[x-1][y]=true;
                q.push({grid[x-1][y],{x-1,y}});
            }
             if(y>0&&visited[x][y-1]==false){
                visited[x][y-1]=true;
                q.push({grid[x][y-1],{x,y-1}});
            }
             if(x<m-1&&visited[x+1][y]==false){
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
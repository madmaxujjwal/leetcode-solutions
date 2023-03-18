class Solution {
public:
    int ab(int d){
        
        if(d<0)return 0-d;
        return d;
    }
    int maxi(int a,int bi){
        if(a>bi)return a;
        return bi;
    }
    void dijastra(int m,int n,vector<vector<int>>& heights,vector<vector<int>> &d,vector<vector<bool>> &vis){
        
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        pq.push({0,{0,0}});
        d[0][0]=0;
        while(pq.size()>0){
            
            int di=pq.top().first;
            int x=pq.top().second.first;
            int y=pq.top().second.second;
            
             vis[x][y]=true;
            pq.pop();
            if(x-1>=0&&y>=0&&vis[x-1][y]==false){
                if(maxi(ab(heights[x-1][y]-heights[x][y]),di)<d[x-1][y]){
                    pq.push({maxi(ab(heights[x-1][y]-heights[x][y]),di),{x-1,y}});
                    d[x-1][y]=maxi(ab(heights[x-1][y]-heights[x][y]),di);
                }
            }
           
             if(x+1<m&&y>=0&&vis[x+1][y]==false){
                if(maxi(ab(heights[x+1][y]-heights[x][y]),di)<d[x+1][y]){
                    pq.push({maxi(ab(heights[x+1][y]-heights[x][y]),di),{x+1,y}});
                    d[x+1][y]=maxi(ab(heights[x+1][y]-heights[x][y]),di);
                }
            }
              if(x>=0&&y+1<n&&vis[x][y+1]==false){
                if(maxi(ab(heights[x][y+1]-heights[x][y]),di)<d[x][y+1]){
                    pq.push({maxi(ab(heights[x][y+1]-heights[x][y]),di),{x,y+1}});
                    d[x][y+1]=maxi(ab(heights[x][y+1]-heights[x][y]),di);
                }
            }
             if(y-1>=0&&vis[x][y-1]==false){
                if(maxi(ab(heights[x][y-1]-heights[x][y]),di)<d[x][y-1]){
                    pq.push({maxi(ab(heights[x][y-1]-heights[x][y]),di),{x,y-1}});
                    d[x][y-1]=maxi(ab(heights[x][y-1]-heights[x][y]),di);
                }
            }
        }
        
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m=heights.size();
        int n=heights[0].size();
        vector<vector<int>> d(m,vector<int>(n,INT_MAX));
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        dijastra(m,n,heights,d,vis);
        return d[m-1][n-1];
    }
};
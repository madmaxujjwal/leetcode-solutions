class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m=mat.size();
        int n=mat[0].size();
        vector<vector<int>> ans(m,vector<int>(n,-1));
        
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int d=q.front().second;
            ans[x][y]=d;
            mat[x][y]=0;
            q.pop();
            if(x>0&&mat[x-1][y]==1){
                q.push({{x-1,y},d+1});
                ans[x-1][y]=d+1;
                mat[x-1][y]=0;
            }
            if(y>0&&mat[x][y-1]==1){
                q.push({{x,y-1},d+1});
                ans[x][y-1]=d+1;
                mat[x][y-1]=0;
            }
            if(x<m-1&&mat[x+1][y]==1){
                q.push({{x+1,y},d+1});
                ans[x+1][y]=d+1;
                mat[x+1][y]=0;
            }
            if(y<n-1&&mat[x][y+1]==1){
                q.push({{x,y+1},d+1});
                ans[x][y+1]=d+1;
                mat[x][y+1]=0;
            }
        }
        return ans;
    }
};
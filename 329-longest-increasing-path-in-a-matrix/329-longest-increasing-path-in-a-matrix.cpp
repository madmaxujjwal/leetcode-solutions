class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& vis,int i,int j,int m,int n){
        if(vis[i][j]!=0){
            return vis[i][j];
        }
        int v=matrix[i][j];int a=0;int b=0;int c=0;int d=0;
        if((i-1)>=0&&v<matrix[i-1][j]){
             a=dfs(matrix,vis,i-1,j,m,n);
        }
        if((i+1)<m&&v<matrix[i+1][j]){
             b=dfs(matrix,vis,i+1,j,m,n);
        }
        if((j-1)>=0&&v<matrix[i][j-1]){
             c=dfs(matrix,vis,i,j-1,m,n);
        }
        if((j+1)<n&&v<matrix[i][j+1]){
             d=dfs(matrix,vis,i,j+1,m,n);
        }
        int res=1+max(a,max(b,max(c,d)));
        return vis[i][j]=res;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        int ans=1;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans=max(ans,dfs(matrix,vis,i,j,m,n));
            }
        }
        return ans;
    }
};
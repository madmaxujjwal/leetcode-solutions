class Solution {
public:
    int m;int n;vector<vector<int>> g;int dp[1001][1001];
    int mod=1e9+7;
    int rec(int i,int j){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int a=0;
        int b=0;
        int c=0;
        int d=0;
        if((i-1)>=0&&g[i-1][j]>g[i][j]){
            a=rec(i-1,j);
        }
        if((i+1)<m&&g[i+1][j]>g[i][j]){
            b=rec(i+1,j);
        }
        if((j-1)>=0&&g[i][j-1]>g[i][j]){
            c=rec(i,j-1);
        }
        if((j+1)<n&&g[i][j+1]>g[i][j]){
            d=rec(i,j+1);
        }
        return   dp[i][j]=(1%mod+a%mod+b%mod+c%mod+d%mod)%mod;
    }
    int countPaths(vector<vector<int>>& grid) {
        m=grid.size();
        n=grid[0].size();
        g=grid;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                
                
                ans=(ans%mod+rec(i,j)%mod)%mod;
            }
        }
        return ans;
    }
};
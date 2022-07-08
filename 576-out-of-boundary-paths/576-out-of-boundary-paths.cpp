class Solution {
public:
    long long int dp[51][51][51];
    int ni;
    int mi;
    int mod=1e9+7;
    long long int rec(int i,int j,int N){
        if(N<0)
            return 0;
        if(i<0||i>=mi||j<0||j>=ni)
            return 1;
        if(dp[i][j][N]!=-1)
            return dp[i][j][N]%mod;
        return dp[i][j][N]=(rec(i-1,j,N-1)%mod+rec(i+1,j,N-1)%mod+rec(i,j-1,N-1)%mod+rec(i,j+1,N-1)%mod)%mod;
        
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        memset(dp,-1,sizeof(dp));
        ni=n;mi=m;
        return rec(startRow,startColumn,maxMove)%mod;
    }
};
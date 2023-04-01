class Solution {
public:
    int m;
    int n;
    int mod=1e9+7;
    int ki;
    
  
    int numberOfPaths(vector<vector<int>>& grid, int k) {
         m=grid.size();
         n=grid[0].size();
        ki=k;
       
        int dp[m+1][n+1][k+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=m;i++){
            for(int j=0;j<k;j++)
            dp[i][0][j]=0;
        }
        for(int i=0;i<=n;i++){
            for(int j=0;j<k;j++)
            dp[0][i][j]=0;
        }
        // dp[1][1][0]=1;
       
        for(int i=0;i<k;i++){
            if(grid[0][0]%k==i){
                dp[1][1][i]=1;
            }
            else
                dp[1][1][i]=0;
        }
        
        for(int i=1;i<=m;i++){
            
            
            for(int j=1;j<=n;j++){
                
                for(int d=0;d<k;d++){
                    if(i==1&&j==1)
                    {
                        continue;
                    }
                    else
                    dp[i][j][d]=(dp[i-1][j][(d-grid[i-1][j-1]%k+k)%k]%mod+dp[i][j-1][(d-grid[i-1][j-1]%k+k)%k]%mod)%mod;
                }
                
            }
        }
       return dp[m][n][0];
        
    }
};
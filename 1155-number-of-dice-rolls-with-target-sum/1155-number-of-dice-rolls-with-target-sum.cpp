class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int m=1e9+7;
         vector<vector<long long int>> dp(n+1,vector<long long int>(target+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=target;j++){
                for(int l=1;l<=k;l++){
                    if(j>=l)
                    dp[i][j]=(dp[i][j]%m+dp[i-1][j-l]%m)%m;
                   
                }
            }
        }
        return (dp[n][target])%m;
    }
};
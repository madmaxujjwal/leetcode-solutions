class Solution {
public:
    int nthUglyNumber(int n) {
       // return 1;
       long long int dp[n+1];
        dp[1]=1;
        for(int i=2;i<=n;i++){
            dp[i]=INT_MAX;
            for(int j=1;j<i;j++){
                if(dp[j]*2>dp[i-1]){
                    dp[i]=min(dp[i],dp[j]*2);
                }
                 if(dp[j]*3>dp[i-1]){
                    dp[i]=min(dp[i],dp[j]*3);
                }
                 if(dp[j]*5>dp[i-1]){
                    dp[i]=min(dp[i],dp[j]*5);
                }
            }
        }
        return dp[n];
    }
};
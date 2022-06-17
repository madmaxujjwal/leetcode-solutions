class Solution {
public:
    int countOrders(int n) {
        int m=1e9+7;
        long long int dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++){
          long long int z=((i%m)*((2*i-1)%m))%m;
            dp[i]=(dp[i-1]*z)%m;
        }
        return dp[n];
    }
};
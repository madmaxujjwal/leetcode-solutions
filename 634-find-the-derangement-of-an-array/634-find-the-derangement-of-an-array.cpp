class Solution {
public:
    int findDerangement(int n) {
       long long  int dp[n+1];int m=1e9+7;
        dp[1]=0;
        
        if(n==1)
            return 0;
        dp[2]=1;
        if(n==2)
            return 1;
        for(int i=3;i<=n;i++){
            dp[i]=(((i-1)%m)*((dp[i-1]%m+dp[i-2]%m))%m)%m;
        }
        return dp[n];
    }
};
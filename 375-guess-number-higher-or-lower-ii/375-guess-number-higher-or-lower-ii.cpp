class Solution {
public:
    int dp[201][201];
    int rec(int i,int j){
        if(i>=j)
            return 0;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=INT_MAX;
        for(int k=i;k<=j;k++){
            ans=min(ans,k+max(rec(i,k-1),rec(k+1,j)));
        }
        return dp[i][j]=ans;
    }
    int getMoneyAmount(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(1,n);
    }
};
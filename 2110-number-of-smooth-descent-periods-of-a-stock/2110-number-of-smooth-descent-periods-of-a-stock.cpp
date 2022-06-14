class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        long long int dp[n];
        dp[0]=1;
        long long int ans=0;
        for(int i=1;i<n;i++){
            if((prices[i]-prices[i-1])==-1){
                dp[i]=1+dp[i-1];
            }
            else
                dp[i]=1;
            ans+=dp[i];
        }
        return ans+1;
    }
};
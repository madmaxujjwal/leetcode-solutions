class Solution {
public:
    unordered_map<int,int> dp;
    int maxA(int n) {
        int ans=n;
        if(dp.find(n)!=dp.end())
            return dp[n];
        for(int i=1;i<n-2;i++){
            ans=max(ans,maxA(i)*(n-i-1));
        }
        return dp[n]=ans;
    }
};
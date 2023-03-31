class Solution {
public:
    vector<vector<int>> type;
    unordered_map<string,int> dp;
    int mod=1e9+7;
    int rec(int i,int sum,vector<vector<int>> &dp){
        if(i<0&&sum==0)return 1;
        if(i<0&&sum!=0)return 0;
        if(sum<0)return 0;
        int ans=0;
        
        if(dp[i][sum]!=-1)return dp[i][sum];
        for(int j=0;j<=type[i][0];j++){
            if(sum-type[i][1]*j>=0)
            ans=(ans%mod+rec(i-1,sum-type[i][1]*j,dp)%mod)%mod;
        }
        
        return dp[i][sum]= ans;
        
    }
    int waysToReachTarget(int target, vector<vector<int>>& types) {
        type=types;
        int n=types.size();
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        return rec(n-1,target,dp);
    }
};
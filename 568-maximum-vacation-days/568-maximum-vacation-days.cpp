class Solution {
public:
    int n;
    int k;
    
    vector<vector<int>> f;
    vector<vector<int>> d;
    long long int rec(int z,int j,vector<vector<int>> &dp){
        if(j==k)return 0;
        if(dp[z][j]!=-1)
            return dp[z][j];
        long long int ans=INT_MIN;
        for(int i=0;i<n;i++){
            if(i!=z&&f[z][i]==1)
                ans=max(ans,d[i][j]+rec(i,j+1,dp));
            else if(i==z){
                ans=max(ans,d[z][j]+rec(i,j+1,dp));
            }
        }
        return dp[z][j]=ans;
    }
    
    int maxVacationDays(vector<vector<int>>& flights, vector<vector<int>>& days) {
        n=flights.size();
        k=days[0].size();
        vector<vector<int>> dp(102,vector<int>(102,-1));
        f=flights;
        d=days;
        return rec(0,0,dp);
    }
};
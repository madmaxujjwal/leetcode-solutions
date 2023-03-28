class Solution {
public:
    vector<int> num;
    int n;
    
    int rec(int i,int j,vector<vector<int>> &dp){
               
        if(i>j||i<0||j>=n)return 0;
        if(dp[i][j]!=-1)return dp[i][j];
         int ans=0;
        for(int k=i;k<=j;k++){
            
            int a=1;
            if(i-1>=0){
                a=num[i-1];
            }
            int b=1;
            if(j+1<n){
                b=num[j+1];
            }
            ans=max(ans,rec(i,k-1,dp)+rec(k+1,j,dp)+a*b*num[k]);
        }
        return dp[i][j]=ans;
    }
    int maxCoins(vector<int>& nums) {
        n=nums.size();
        num=nums;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        return rec(0,n-1,dp);
    }
};
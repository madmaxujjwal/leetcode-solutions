class Solution {
public:
    vector<int> num;
    int n;
    vector<int> pr;
    int rec(int i,int k,vector<vector<int>> &dp){
        if(k==1){
            return pr[i];
        }
        if(i<0||k<=0)return 0;
        if(dp[i][k]!=-1)return dp[i][k];
        int ans=INT_MAX;
        int sum=0;
        for(int j=i;j>=0;j--){
            sum=sum+num[j];
            if(j>=k-1&&k>0)
            ans=min(ans,max(sum,rec(j-1,k-1,dp)));
        }
        
        return dp[i][k]=ans;
    }
    int splitArray(vector<int>& nums, int m) {
        n=nums.size();
        num=nums;
        int sum=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
            pr.push_back(sum);
        }
        return rec(n-1,m,dp);
    }
};
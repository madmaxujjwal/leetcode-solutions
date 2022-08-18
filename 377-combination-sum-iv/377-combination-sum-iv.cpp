class Solution {
public:
    vector<int> num;
    int dp[201][1001];
    int n;
    int rec(int x,int t){
        if((t-num[x])==0)
            return 1;
        if((t-num[x])<0)
            return 0;
        if
            (dp[x][t]!=-1)
            return dp[x][t];
        int ans=0;
        
        for(int i=0;i<n;i++){
            ans+=rec(i,t-num[x]);
        }
         return dp[x][t]= ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        n=nums.size();
        num=nums;
        int ans=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++){
            ans+=rec(i,target);
        }
        return ans;
    }
};
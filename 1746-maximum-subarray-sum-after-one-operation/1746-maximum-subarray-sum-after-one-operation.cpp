class Solution {
public:
    int maxSumAfterOperation(vector<int>& nums) {
        int n=nums.size();int dp1[n];
        int dp[n];dp[0]=nums[0]*nums[0];
        dp1[0]=nums[0];
        int maxi=dp[0];
        for(int i=1;i<n;i++){
            dp1[i]=max(dp1[i-1]+nums[i],nums[i]);
        }
        for(int i=1;i<n;i++){
            
            dp[i]=max(nums[i]*nums[i],max(nums[i]*nums[i]+dp1[i-1],dp[i-1]+nums[i]));
            maxi=max(dp[i],maxi);
            
            
            
        }
        return maxi;
    }
};
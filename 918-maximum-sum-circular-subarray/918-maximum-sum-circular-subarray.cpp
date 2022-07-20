class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        int m=INT_MIN;
        int ma=INT_MIN;
        int sum=0;
        vector<int> dp(n,INT_MIN);
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            sum+=nums[i];
            if(i==0){
                dp[i]=nums[i];
            }
            else{
                
                dp[i]=max(nums[i],nums[i]+dp[i-1]);
            }
            m=max(m,dp[i]);
            nums[i]=0-nums[i];
        }
        for(int i=0;i<n;i++){
            if(i==0){
                dp[i]=nums[i];
            }
            else{
                
                dp[i]=max(nums[i],nums[i]+dp[i-1]);
            }
            ma=max(ma,dp[i]);
        }
        if(maxi<0)
            return maxi;
        int ans=sum+ma;
        ans=max({ans,m});
        return ans;
        
    }
};
class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int n=nums.size();
        int dp1[n];dp1[0]=nums[0];int maxi=nums[0];
        int dp2[n];dp2[0]=nums[0];int mini=nums[0];
        for(int i=1;i<n;i++){
            if(dp1[i-1]+nums[i]>nums[i])
                dp1[i]=dp1[i-1]+nums[i];
             else
                 dp1[i]=nums[i];
            maxi=max(maxi,dp1[i]);
        }
        
        
        for(int i=1;i<n;i++){
            if(dp2[i-1]+nums[i]<nums[i])
                dp2[i]=dp2[i-1]+nums[i];
             else
                 dp2[i]=nums[i];
            mini=min(mini,dp2[i]);
        }
        int ans=max(abs(maxi),abs(mini));
        return ans;
      
    }
};
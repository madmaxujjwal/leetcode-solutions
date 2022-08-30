class Solution {
public:
    long long maximumAlternatingSubarraySum(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return nums[0];
        long long int dpp[n];
        long long int dpn[n];
        dpp[0]=nums[0];
        dpn[0]=0;
        long long int ans=max(dpp[0],dpn[0]);
        for(int i=1;i<n;i++){
            dpp[i]=max((dpn[i-1]+nums[i]),(long long int)(nums[i]));
            dpn[i]=max((dpp[i-1]-nums[i]),(long long int)0);
            ans=max({ans,dpp[i],dpn[i]});
        }
            
        return ans;
    }
};
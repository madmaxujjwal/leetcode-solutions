class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n=nums.size();
        long long int dpp[n];
        long long int dpn[n];
        dpp[0]=nums[0];
        dpn[0]=0;
        long long int ans=max(dpp[0],dpn[0]);
        
        for(int i=1;i<n;i++){
            
            dpp[i]=max({dpp[i-1],nums[i]+dpn[i-1],(long long int)nums[i]});
            dpn[i]=max(dpp[i-1]-nums[i],dpn[i-1]);
            ans=max(dpp[i],dpn[i]);
        }
        
        return ans;
        
        
    }
};
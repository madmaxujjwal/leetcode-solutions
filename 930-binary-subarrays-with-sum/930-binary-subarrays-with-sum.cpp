class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n=nums.size();
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        unordered_map<int,int> ht;
        int c=0;
        for(int i=0;i<=n;i++){
            c+=ht[sum[i]-goal];
            ht[sum[i]]++;
        }
        
        return c;
        
    }
};
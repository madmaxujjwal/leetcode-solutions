class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int k=nums.size();
        vector<int> f(k);int sum=0;
        for(int i=0;i<k;i++){
            f[0]+=i*nums[i];
            sum+=nums[i];
        }
        int ans=f[0];
        for(int i=1;i<k;i++){
            f[i]=f[i-1]+sum-k*nums[k-i];
            ans=max(ans,f[i]);
        }
        return ans;
    }
};
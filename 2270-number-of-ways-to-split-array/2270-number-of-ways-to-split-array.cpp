class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long int n=nums.size();long long int c=0;
        vector<long long int> sum(n);
        sum[0]=nums[0];
        long long int s=0;
        for(int i=0;i<n;i++)
            s+=nums[i];
        for(int i=0;i<n-1;i++){
            if(i!=0){
                sum[i]=sum[i-1]+nums[i];
            }
            long long int rest=s-sum[i];
            if(sum[i]>=rest)c++;
        }
        return c;
    }
};
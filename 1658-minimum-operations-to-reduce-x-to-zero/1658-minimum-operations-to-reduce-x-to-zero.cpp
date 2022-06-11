class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        if(x==0){
            return 0;
        }
        int n=nums.size();
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        int s=0;int ans=INT_MAX;
        for(int i=0;i<n;i++){
            int index=lower_bound(sum.begin(),sum.end()-i,x-s)-sum.begin();
            if((index<=n-i)&&(sum[index]==(x-s))){
                ans=min(ans,i+index);
            }
            s=s+nums[n-1-i];
            
        }
        if(ans==INT_MAX)
            return -1;
        return ans;
    }
};
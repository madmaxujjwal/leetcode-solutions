class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        int n=nums.size();
        int a=firstLen;
        int b=secondLen;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+nums[i-1];
        }
        int maxi=INT_MIN;
        for(int i=1;i<=n;i++){
            int sum1;
            if((i-a)<0)
                continue;
             sum1=sum[i]-sum[i-a];
            for(int j=i+1;j<=n;j++){
                int sum2;
                if((j-b)<i){
                    continue;
                }
            sum2=sum[j]-sum[j-b];
                maxi=max(maxi,sum1+sum2);
            }
        }
         for(int i=1;i<=n;i++){
            int sum1;
            if((i-b)<0)
                continue;
             sum1=sum[i]-sum[i-b];
            for(int j=i+1;j<=n;j++){
                int sum2;
                if((j-a)<i){
                    continue;
                }
            sum2=sum[j]-sum[j-a];
              maxi=max(maxi,sum1+sum2);
            }
        }
        return maxi;
    }
};
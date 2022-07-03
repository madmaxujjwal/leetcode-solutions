class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int dp[n+1][m+1];int max1=INT_MIN;int max2=INT_MIN;int a=INT_MAX;int b=INT_MAX;
        for(int i=0;i<=n;i++)
        {dp[i][0]=0;
         if(i<n){
             max1=max(max1,nums1[i]);
             a=min(a,abs(nums1[i]));
         }
        }
        for(int i=0;i<=m;i++)
        {dp[0][i]=0;
         if(i<m){
             max2=max(max2,nums2[i]);
              b=min(b,abs(nums2[i]));
         }
        }
        dp[0][0]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                dp[i][j]=max({nums1[i-1]*nums2[j-1]+dp[i-1][j-1],dp[i-1][j-1],dp[i][j-1],dp[i-1][j]});
            }
        }
        if(max1*max2<0)
            return 0-a*b;
        return dp[n][m];
    }
};
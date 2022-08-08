class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n=arr.size();
        int dp1[n];
        int dp2[n];
        dp1[0]=1;
        for(int i=1;i<n;i++){
            if(arr[i]>arr[i-1]){
                dp1[i]=1+dp1[i-1];
            }
            else{
                dp1[i]=1;
            }
        }
        dp2[n-1]=1;
        for(int i=n-2;i>=0;i--){
            if(arr[i]>arr[i+1]){
                dp2[i]=1+dp2[i+1];
            }
            else
                dp2[i]=1;
        }
        int ans=0;
        for(int i=1;i<n-1;i++){
            if(dp1[i]>1&&dp2[i]>1)
            ans=max(ans,dp1[i]+dp2[i]-1);
        }
        return ans;
    }
};
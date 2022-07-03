class Solution {
public:
    int maximumSum(vector<int>& arr) {
        
        int n=arr.size();int ans=INT_MIN;
        if(n==1)
            return arr[0];
        vector<int> dp1(n);
        vector<int> dp2(n);
        dp1[0]=arr[0];
        for(int i=1;i<n;i++){
            dp1[i]=max(dp1[i-1]+arr[i],arr[i]);
            ans=max(ans,dp1[i]);
        }
        dp2[0]=arr[n-1];
        reverse(arr.begin(),arr.end());
        for(int i=1;i<n;i++){
            dp2[i]=max(dp2[i-1]+arr[i],arr[i]);
            ans=max(ans,dp2[i]);
        }
        ans=max({ans,dp1[0],dp2[0]});
        reverse(arr.begin(),arr.end());
        for(int i=0;i<n;i++){
            int a=0;int b=0;
            if(i>0){
                a=dp1[i-1];
            }
            if(i<n-1){
                b=dp2[n-2-i];
            }
            ans=max(ans,a+b);
        }
        return ans;
    }
};
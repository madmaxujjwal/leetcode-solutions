class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int n=values.size();
        vector<int> a(n);
        vector<int> b(n);
        vector<int> dp(n,INT_MIN);
        
        for(int i=0;i<n;i++){
            a[i]=values[i]+i;
            b[i]=values[i]-i;
            if(i==0){
                dp[i]=a[i];
            }
            else{
                dp[i]=max(dp[i-1],a[i]);
            }
        }
        int ans=INT_MIN;
        for(int i=n-1;i>0;i--){
            ans=max(ans,b[i]+dp[i-1]);
        }
        return ans;
        
    }
};
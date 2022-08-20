class Solution {
public:
    
         static bool sortbycol(const vector<int>& v1, const vector<int>& v2)
{
    return v1[0] < v2[0];
}
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        
        sort(pairs.begin(),pairs.end(),sortbycol);
        vector<int> dp(n,1);
        dp[0]=1;
        int ans=1;
        for(int i=1;i<n;i++){
            for(int j=i-1;j>=0;j--){
                if(pairs[i][0]>pairs[j][1]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};
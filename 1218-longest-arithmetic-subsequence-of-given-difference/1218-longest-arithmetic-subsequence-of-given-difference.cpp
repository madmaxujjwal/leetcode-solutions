class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n=arr.size();
        int d=difference;
        vector<int> dp(n+1);
        unordered_map<int,int> ht;
        dp[1]=1;
        dp[0]=0;
        ht[arr[0]]=0;
        int ans=1;
        for(int i=2;i<=n;i++){
            if(ht.find(arr[i-1]-d)==ht.end())
                dp[i]=1;
            else{
                dp[i]=1+dp[ht[arr[i-1]-d]+1];
            }
            ht[arr[i-1]]=i-1;
            ans=max(ans,dp[i]);
        }
        
        return ans;
 }

};
class Solution {
public:
   // bool comp(pair<int,int> &a,pair<int,int> &b){
        
        
   // }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n=scores.size();
        vector<pair<int,int>> z;
        for(int i=0;i<n;i++){
            z.push_back({ages[i],scores[i]});
        }
        sort(z.begin(),z.end());
        vector<int> dp(n,0);
        dp[0]=z[0].second;
        int ans=dp[0];
        for(int i=1;i<n;i++){
            dp[i]=z[i].second;
            for(int j=0;j<i;j++){
                if(z[i].second>=z[j].second)
                dp[i]=max(dp[i],z[i].second+dp[j]);
                   
                
            }
            ans=max(ans,dp[i]);
        }
        return ans;
        
    }
};
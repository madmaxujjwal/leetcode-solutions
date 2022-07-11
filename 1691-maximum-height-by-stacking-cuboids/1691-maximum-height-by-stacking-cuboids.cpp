class Solution {
public:
    static bool comp(vector<int> &a,vector<int> &b){
        if(a[0]==b[0]){
            if(a[1]==b[1]){
                return a[2]<b[2];
            }
            else{
                return a[1]<b[1];
            }
        }
        else
            return a[0]<b[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        int n=cuboids.size();
        for(int i=0;i<n;i++){
            sort(cuboids[i].begin(),cuboids[i].end(),greater<int>());   
        }
        sort(cuboids.begin(),cuboids.end(),comp);
        vector<int> dp(n,0);
        for(int i=0;i<n;i++)
            dp[i]=cuboids[i][0];
        dp[0]=cuboids[0][0];
        int ans=dp[0];
      //  return ans;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if((cuboids[i][0]>=cuboids[j][0])&&(cuboids[i][1]>=cuboids[j][1])&&(cuboids[i][2]>=cuboids[j][2])){
                    dp[i]=max(dp[i],cuboids[i][0]+dp[j]);
                }
            }
            ans=max(ans,dp[i]);
        }
        
        
        
        return ans;
    }
    
};
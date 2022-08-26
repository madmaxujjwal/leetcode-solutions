class Solution {
public:
    int numOfWays(int n) {
      long long int dp[n][12];int m=1e9+7; 
      for(int i=0;i<12;i++){
          dp[0][i]=1;
      }
       for(int i=1;i<n;i++){
           dp[i][0]=(dp[i-1][4]%m+dp[i-1][5]%m+dp[i-1][7]%m+dp[i-1][8]%m+dp[i-1][9]%m)%m;
           dp[i][1]=(dp[i-1][4]%m+dp[i-1][6]%m+dp[i-1][7]%m+dp[i-1][8]%m)%m;
           dp[i][2]=(dp[i-1][4]%m+dp[i-1][5]%m+dp[i-1][8]%m+dp[i-1][9]%m+dp[i-1][11]%m)%m;
           dp[i][3]=(dp[i-1][5]%m+dp[i-1][10]%m+dp[i-1][9]%m+dp[i-1][11]%m)%m;
           dp[i][4]=(dp[i-1][0]%m+dp[i-1][1]%m+dp[i-1][2]%m+dp[i-1][10]%m+dp[i-1][11]%m)%m;
           dp[i][5]=(dp[i-1][0]%m+dp[i-1][2]%m+dp[i-1][10]%m+dp[i-1][3]%m)%m;
           dp[i][6]=(dp[i-1][1]%m+dp[i-1][8]%m+dp[i-1][9]%m+dp[i-1][11]%m)%m;
           dp[i][7]=(dp[i-1][0]%m+dp[i-1][1]%m+dp[i-1][9]%m+dp[i-1][10]%m+dp[i-1][11]%m)%m;
           dp[i][8]=(dp[i-1][0]%m+dp[i-1][1]%m+dp[i-1][2]%m+dp[i-1][6]%m)%m;
           dp[i][9]=(dp[i-1][0]%m+dp[i-1][2]%m+dp[i-1][3]%m+dp[i-1][6]%m+dp[i-1][7]%m)%m;
           dp[i][10]=(dp[i-1][4]%m+dp[i-1][5]%m+dp[i-1][3]%m+dp[i-1][7]%m)%m;
           dp[i][11]=(dp[i-1][2]%m+dp[i-1][3]%m+dp[i-1][4]%m+dp[i-1][6]%m+dp[i-1][7]%m)%m;
           
           
           
           
           
           
       }
        
        
        long long int ans=0;
        for(int i=0;i<12;i++){
            ans=(ans%m+dp[n-1][i])%m;
        }
        return ans;
    }
};
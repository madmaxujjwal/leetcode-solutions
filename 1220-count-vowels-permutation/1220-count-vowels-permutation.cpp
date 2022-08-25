class Solution {
public:
    int countVowelPermutation(int n) {
        long long int dp[n][5];
        long long int m=1e9+7; 
        for(int i=0;i<5;i++){
            dp[0][i]=1;
        }
        for(int i=1;i<n;i++){
            
                
                dp[i][0]=(dp[i-1][4]%m+dp[i-1][1]%m+dp[i-1][2]%m)%m;
                dp[i][1]=(dp[i-1][0]%m+dp[i-1][2]%m)%m;
                dp[i][2]=(dp[i-1][1]%m+dp[i-1][3]%m)%m;
                dp[i][3]=dp[i-1][2]%m;
                dp[i][4]=(dp[i-1][3]%m+dp[i-1][2]%m)%m;
                
            
        }
        long long int ans=0;
        for(int i=0;i<5;i++){
            ans=(ans%m+dp[n-1][i]%m)%m;
        }
        return ans;
    }
};
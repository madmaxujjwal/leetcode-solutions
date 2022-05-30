class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n=s1.size();
        int m=s2.size();
        if(s3.size()!=(s1.size()+s2.size()))
            return false;
        if(n==1&&m==1&&s1+s2==s3)
            return true;
       vector<vector<bool>> dp(n+1,vector<bool>(m+1));
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0&&j==0)
                    dp[i][j]=true;
                else if(i!=0&&j!=0){
                    if(((s3[i+j-1]==s2[j-1])&&(dp[i][j-1]==true))||((s3[i+j-1]==s1[i-1])&&(dp[i-1][j]==true)))
                        dp[i][j]=true;
                }
                else if(i!=0&&j==0){
                    if((s3[i+j-1]==s1[i-1]&&dp[i-1][j]==true))
                        dp[i][j]=true;
                }
                else{
                    if((s3[i+j-1]==s2[j-1]&&dp[i][j-1]==true))
                        dp[i][j]=true;
                }
                 }
        }
        return dp[n][m];
    }
};
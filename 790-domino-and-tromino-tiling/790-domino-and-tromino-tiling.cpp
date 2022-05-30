class Solution {
public:
    int m=1e9+7;
    int numTilings(int n) {
        vector<int> dp(n+1,0);
        if(n==1)
            return 1;
        if(n==2)
            return 2;
        if(n==3)
            return 5;
        dp[0]=1;
        dp[1]=1;
        dp[2]=2;
        dp[3]=5;
      //  dp[4]=11;
      //  dp[5]=24;
      //  dp[6]=53;
     //   dp[7]=117;
        for(int i=4;i<=n;i++){
            for(int j=1;j<=i;j++){
                if(j<=2)
                dp[i]=(dp[i]+dp[i-j]%m)%m;
                else{
                 dp[i]=(dp[i]+((dp[i-j]%m)*2)%m)%m;   
                }
            }
           
        }
        return dp[n];
    }
};
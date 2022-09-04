class Solution {
public:
    int countTexts(string pressedKeys) {
        long long int m=1e9+7;
        int n=pressedKeys.size();
        string p=pressedKeys;
        long long int dp[n+1];
        dp[0]=1;
        for(int i=1;i<=n;i++)
        {
            int a=0;
            int b=0;
            int c=0;
            int d=0;
            a=dp[i-1];
            if(i>1&&p[i-1]==p[i-2])
                b=dp[i-2]%m;
            if(i>2&&p[i-1]==p[i-2]&&p[i-2]==p[i-3])
                c=dp[i-3]%m;
            if(i>3&&p[i-1]==p[i-2]&&p[i-2]==p[i-3]&&p[i-3]==p[i-4]&&((p[i-1]=='9')||(p[i-1]=='7')))
               d=dp[i-4]%m;
            
                
            dp[i]=(a%m+b%m+c%m+d%m)%m;
            
        }
        
        return dp[n];
    }
};
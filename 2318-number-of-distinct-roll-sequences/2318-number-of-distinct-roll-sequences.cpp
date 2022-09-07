class Solution {
public:
    long long int mod=1e9+7;
    long long int dp[7][7][10001];
    long long int hcf(int a, int b)
{
    // Everything divides 0
    if (a == 0)
       return b;
    if (b == 0)
       return a;
  
    // base case
    if (a == b)
        return a;
  
    // a is greater
    if (a > b)
        return hcf(a-b, b);
    return hcf(a, b-a);
}
    long long int rec(int x,int y,int n){
        long long int ans=0;
        if(x!=-1&&y!=-1){
            if(dp[x][y][n]!=-1)
                return dp[x][y][n];
        }
        if(n==0){
            return 1;
        }
        for(int i=1;i<=6;i++){
             if(x==-1&&y==-1){
                 
                 ans=(ans%mod+rec(y,i,n-1)%mod)%mod;
             }
             else if(i!=x&&i!=y&&hcf(i,y)==1){
                ans=(ans%mod+rec(y,i,n-1)%mod)%mod;
            }
            
        }
        if(x!=-1&&y!=-1){
            return dp[x][y][n]=ans;
        }
        return ans;
        
    }
    int distinctSequences(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(-1,-1,n);
    }
};
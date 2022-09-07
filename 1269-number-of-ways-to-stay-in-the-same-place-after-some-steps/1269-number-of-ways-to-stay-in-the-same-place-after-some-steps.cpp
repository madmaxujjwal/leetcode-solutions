class Solution {
public:
    long long int n;long long int mod=1e9+7;long long int dp[501][501];
   long long int rec(int x,int k){
        if(k==0){
            
            if(x==0)return 1;
            else
                return 0;
        }
        if(dp[x][k]!=-1)return dp[x][k];
        long long int a=0;
        long long int b=0;
        long long int c=0;
        b=rec(x,k-1);
        if(x>0){
            a=rec(x-1,k-1);
        }
        if(x<n-1){
            c=rec(x+1,k-1);
        }
        return  dp[x][k]=( a%mod+b%mod+c%mod)%mod;
        
    }
    int numWays(int steps, int arrLen) {
        n=arrLen;
       for(int i=0;i<501;i++){
           for(int j=0;j<501;j++){
               dp[i][j]=-1;
           }
       }
        return rec(0,steps);
    }
};
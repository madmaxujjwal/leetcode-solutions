class Solution {
public:
    vector<int> g;
    vector<int> p;
    int dp[101][101][101];
    int mod=1e9+7;
    int rec(int n,int m,int l){
        if(n<0)
            return 0;
       
        if(l==0){
            if(n>=0&&(m==0)){
                return 1;
            }
            else
                return 0;
        }
         if(dp[n][m][l]!=-1)
            return dp[n][m][l];
            
        int sd=m-p[l-1];
        sd=max(0,sd);
        int fd=n-g[l-1];
        int res=0;
        if(fd<0)
            res= 0;
        else
            res=rec(fd,sd,l-1);
        return dp[n][m][l]= (res%mod+rec(n,m,l-1)%mod)%mod;
        
    }
    
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        g=group;p=profit;
        int l=profit.size();
        memset(dp,-1,sizeof(dp));
        return rec(n,minProfit,l);
    }
};
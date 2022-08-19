class Solution {
public:
    vector<double> p;int n;
    double dp[1001][1001];
    double rec(int x,int t){
        if(t==0&&x==0){
            return 1;
        }
        
        if(x==0&&t>0)
            return 0;
        if(t==0&&x!=0){
            dp[x][t]= (1-p[x-1])*rec(x-1,t);
        }
        if(dp[x][t]!=-1)
            return dp[x][t];
        return dp[x][t]= p[x-1]*rec(x-1,t-1)+(1-p[x-1])*rec(x-1,t);
    }
    double probabilityOfHeads(vector<double>& prob, int target) {
        
        int n=prob.size();
       
        if(target>n)
            return 0;
       dp[0][0]=1;
        for(int i=1;i<=target;i++){
            dp[0][i]=0;
        }
        for(int i=1;i<=n;i++){
            for(int j=0;j<=target;j++){
                if(j!=0)
                dp[i][j]= prob[i-1]*dp[i-1][j-1]+(1-prob[i-1])*dp[i-1][j];
                else
                dp[i][j]= (1-prob[i-1])*dp[i-1][j];
                
            }
        }
        return dp[n][target];
    }
};
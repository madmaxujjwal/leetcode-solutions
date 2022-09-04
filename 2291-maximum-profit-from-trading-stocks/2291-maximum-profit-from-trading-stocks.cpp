class Solution {
public:
    
    vector<int> p;
    vector<int> f;
    int dp[1001][1001];
    int rec(int i,int j){
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(i==0)
            return 0;
        if(p[i-1]<=j&&p[i-1]<f[i-1]){
            
            return dp[i][j]= max((f[i-1]-p[i-1]+rec(i-1,j-p[i-1])),rec(i-1,j));
        }
        else
            return dp[i][j]=rec(i-1,j);
        
    }
    int maximumProfit(vector<int>& present, vector<int>& future, int budget) {
        p=present;
        f=future;
        int n=p.size();
        memset(dp,-1,sizeof(dp));
        return rec(n,budget);
    }
};
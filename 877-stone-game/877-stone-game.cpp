class Solution {
public:
    int dp[501][501];
    int rec(vector<int> piles,int i,int j){
        if(i==j){
            return piles[i];
        }
        if(i>j){
            return 0;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        
        int a=piles[i]+min(rec(piles,i+2,j),rec(piles,i+1,j-1));
        int b=piles[j]+min(rec(piles,i+1,j-1),rec(piles,i,j-2));
        return  dp[i][j]= max(a,b);
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        int sum=0;
        int n=piles.size();
        for(int i=0;i<n;i++){
            sum+=piles[i];
        }
        int as=rec(piles,0,n-1);
        if(2*as>sum){
            return true;
        }
        return false;
    }
};
class Solution {
public:
    string st;
    int dp[101][101];
    int rec(int i,int j){
        if(i>j)return 0;
        if(i==j)
            return 1;
        if(dp[i][j]!=-1)
            return dp[i][j];
        int ans=j-i+1;
        for(int k=j-1;k>=i;k--){
            if(st[j]==st[k]){
                ans=min(ans,rec(i,k)+rec(k+1,j-1));
            }
            
        }
        ans=min(ans,rec(i,j-1)+1);
        return dp[i][j]=ans;
        
    }
    int strangePrinter(string s) {
        st=s;
        memset(dp,-1,sizeof(dp));
        return rec(0,s.size()-1);
    }
};
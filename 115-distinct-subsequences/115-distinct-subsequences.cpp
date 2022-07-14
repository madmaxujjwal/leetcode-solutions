class Solution {
public:
    int dp[1001][1001];
    string a;string b;
    int rec(int i,int j){
        if(i==0&&j!=0)
            return 0;
        if(j==0){
            return 1;
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        if(a[i-1]==b[j-1]){
            return dp[i][j]= rec(i-1,j-1)+rec(i-1,j);
        }
        else
            return dp[i][j]= rec(i-1,j);
    }
    int numDistinct(string s, string t) {
        a=s;b=t;
        memset(dp,-1,sizeof(dp));
        return rec(s.size(),t.size());
    }
};
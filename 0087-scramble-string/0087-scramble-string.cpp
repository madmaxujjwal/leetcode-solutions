class Solution {
public:
    string a;
    string b;
    int dp[31][31][31];
    bool rec(int i,int j,int x){
        int n=j-i+1;
        int y=x+n-1;
        if(n==0)
            return true;
        if(n==1){
            if(a[i]==b[x])return true;
            else 
                return false;
        }
        if(dp[i][j][x]!=-1)return dp[i][j][x];
        
        for(int k=i;k<j;k++){
            
            if((rec(i,k,x)&&rec(k+1,j,x+k-i+1))||(rec(i,k,i+y-k)&&rec(k+1,j,x)))
                
             return dp[i][j][x]=true;
            
            
        }
        
        return dp[i][j][x]= false;
    }
    bool isScramble(string s1, string s2) {
        int n=s1.size();
        a=s1;
        b=s2;
        
        memset(dp,-1,sizeof(dp));
        return rec(0,n-1,0);
    }
};
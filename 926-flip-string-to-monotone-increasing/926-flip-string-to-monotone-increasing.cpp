class Solution {
public:
    string z;
     int dp[100001][2];
    int rec(int x,int p){
        
        if(x<0)
            return 0;
        if(dp[x][p]!=-1)
            return dp[x][p];
        if(p==0){
            if(z[x]=='0'){
                
                return dp[x][p] =rec(x-1,0);
            }
            else{
                
                return dp[x][p] = 1+rec(x-1,0);
            }
            
            
        }
        else{
            
            if(z[x]=='0'){
                
                return dp[x][p] =min(rec(x-1,0),1+rec(x-1,1));
            }
            else{
                
                return dp[x][p] =min(1+rec(x-1,0),rec(x-1,1));
            }
            
            
        }
        
        
    }
    int minFlipsMonoIncr(string s) {
        memset(dp,-1,sizeof(dp));
        z=s;
        return rec(s.size()-1,1);
    }
};
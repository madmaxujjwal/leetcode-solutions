class Solution {
public:
    string z;int N;int a;
   // int dp[501][501][501];
    int dfs(int i,int x,int y){
        
        if(x<0||x==N||y<0||y==N){
            return -1;
        }
        if(i==a){
            return 0;
        }
        //if(dp[i][x][y]!=-1)return dp[i][x][y];
        if(z[i]=='L'){
            return 1+dfs(i+1,x,y-1);
        }
        else if(z[i]=='R'){
            return 1+dfs(i+1,x,y+1);
        }
        else if(z[i]=='U'){
            return 1+dfs(i+1,x-1,y);
        }
        else{
            return 1+dfs(i+1,x+1,y);
        }
        
    }
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        int x=startPos[0];
        int y=startPos[1];
        z=s;
        N=n;
        a=s.size();
       // memset(dp,-1,sizeof(dp));
        vector<int> ans(a);
        for(int i=0;i<a;i++){
            ans[i]=dfs(i,x,y);
        }
        return ans;
    }
};
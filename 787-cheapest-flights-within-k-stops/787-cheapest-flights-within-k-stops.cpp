class Solution {
public:
    int s;int d;int l;vector<vector<pair<int,int>>> adj;
    int dp[1001][1001];
    int dfs(int i,int j){
        if(j>l){
            return 100000000000;
        }
        if(i==d){
            return 0;
        }
        if(j!=-1&&dp[i][j]!=-1)
            return dp[i][j];
        int ans=100000000000;
        for(auto it:adj[i]){
            ans=min(ans,it.second+dfs(it.first,j+1));
        }
        if(j==-1)
            return ans;
        return dp[i][j]= ans;
    }
    
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        d=dst;s=src;l=k;
        adj.resize(n);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
         
        int ans=dfs(src,-1);
        if(ans>1000000000)
            return -1;
        return ans;
    }
};
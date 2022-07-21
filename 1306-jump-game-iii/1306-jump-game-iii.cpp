class Solution {
public:
    vector<int> a;int n;
    int dp[50000];
    bool visited[50000];
    int dfs(int x){
          if(x<0||x>=n)
            return 0;
        if(visited[x]==true)
            return 0;
        visited[x]=true;
      
        if(a[x]==0)
            return 1;
        if(dp[x]!=-1)
            return dp[x];
        return dp[x]=dfs(x-a[x])|dfs(x+a[x]);
        
    }
    bool canReach(vector<int>& arr, int start) {
        n=arr.size();
        a=arr;
        memset(dp,-1,sizeof(dp));
        memset(visited,false,sizeof(visited));
        int z= dfs(start);
        if(z==1)
            return true;
        else
            return false;
    }
};
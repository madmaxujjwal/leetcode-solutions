class Solution {
public:
    vector<int> z;int n;
    unordered_map<int,int> dp;
    int rec(int x){
        if(x>n){
            return 1000000;
        }
       if(x==n){
           return 0;
       }
        if(dp.find(x)!=dp.end())return dp[x];
        return dp[x]= z[x]+min(rec(x+1),rec(x+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        z=cost;
        n=z.size();
        return min(rec(0),rec(1));
    }
};
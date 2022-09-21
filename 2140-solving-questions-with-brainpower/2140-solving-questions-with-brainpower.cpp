class Solution {
public:
    
    unordered_map<long long int,long long int> dp;
    int n;
    vector<vector<int>> arr;
    
    long long int rec(int x){
        if(x>=n)return 0;
        if(dp.find(x)!=dp.end())return dp[x];
        return dp[x]= max(arr[x][0]+rec(x+arr[x][1]+1),rec(x+1));
        
    }
    long long mostPoints(vector<vector<int>>& questions) {
        arr=questions;
        n=arr.size();
        return rec(0);
    }
};
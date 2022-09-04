class Solution {
public:
    unordered_map<long long int,long long int> dp;
    long long int rec(int n){
        if(dp.find(n)!=dp.end())return dp[n];
        if(n==1){
            return 0;
        }
        if(n%2==0){
            return dp[n]=1+rec(n/2);
        }
        else{
            return dp[n]=1+min(rec(n+1),rec(n-1));
        }
    }
    int integerReplacement(int n) {
        if(n==INT_MAX){
            return rec(n-1);
        }
        return rec(n);
    }
};
class Solution {
public:
    unordered_map<long long int,long long int> dp;
    long long int m=1e9+7;
   long long int rec(long long int i){
        
        if(i==2||i==0){
            return 1;
        }
        if(dp.find(i)!=dp.end())
            return dp[i];
        long long int ans=0;
        for(int j=2;j<=i;j=j+2){
            ans=(ans%m+(rec(j-2)%m)*(rec(i-j)%m))%m;
        }
        return dp[i]=ans;
    }
    int numberOfWays(int numPeople) {
        return rec(numPeople);
        
    }
};
class Solution {
public:
    unordered_map<int,int> dp;
    int minSteps(int n) {
     if(n==1)
         return 0;
     
   
        if(dp.find(n)!=dp.end())
            return dp[n];
        int ans=INT_MAX;
        for(int i=1;i<n;i++){
            if(n%i==0)
                ans=min(ans,(n/i)+minSteps(i));
        }
        return dp[n]= ans;
    }
};
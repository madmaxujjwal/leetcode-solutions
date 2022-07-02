class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        vector<long long int> dp(n);  int k=primes.size();
        vector<long long int> counter(k,0);
      
        dp[0]=1;
        for(int i=1;i<n;i++){
            long long int ele=INT_MAX;
            for(int i=0;i<k;i++){
                ele=min(ele,primes[i]*dp[counter[i]]);
            }
            for(int i=0;i<k;i++){
                if(ele==primes[i]*dp[counter[i]])
                    counter[i]++;
            }
            dp[i]=ele;
        }
        return dp[n-1];
    }
};
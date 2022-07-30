class Solution {
public:
    long long numberOfWays(string s) {
        int n=s.size();
        vector<long long int> dp(n);
        dp[0]=0;
        dp[1]=0;
        vector<long long int> one(n);
        vector<long long int> zero(n);
        if(s[0]=='0'){
           zero[0]=1;
            one[0]=0;
        }
        else{
             zero[0]=0;
            one[0]=1;
        }
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                zero[i]=zero[i-1]+1;
                one[i]=one[i-1];
            }
            else{
                zero[i]=zero[i-1];
                one[i]=one[i-1]+1;
            }
        }
        vector<long long int> zo(n);
        vector<long long int> oz(n);
        zo[0]=0;
        oz[0]=0;
        for(int i=1;i<n;i++){
            if(s[i]=='0'){
                oz[i]=one[i-1]+oz[i-1];
                zo[i]=zo[i-1];
            }
            else{
                zo[i]=zero[i-1]+zo[i-1];
                oz[i]=oz[i-1];
            }
        }
        for(int i=2;i<n;i++){
            if(s[i]=='0'){
                dp[i]=dp[i-1]+zo[i-1];
            }
            else{
                dp[i]=dp[i-1]+oz[i-1];
            }
        }
        return dp[n-1];
    }
};
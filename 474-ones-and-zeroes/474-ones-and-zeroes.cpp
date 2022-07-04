class Solution {
public:
     int dp[101][101][601];
    int calcone(string str){
        int n=str.size();
        int one=0;
        for(int i=0;i<n;i++){
            if(str[i]=='1')
                one++;
        }
        return one;
    }
    int calczero(string str){
         int n=str.size();
        int zero=0;
        for(int i=0;i<n;i++){
            if(str[i]=='0')
                zero++;
        }
        return zero;
    }
    int fun(vector<string>& strs,int m,int n,int l){
        
        if(m<0||n<0)
            return INT_MIN;
        
        if(l==0){
            return 0;
        }
        if(dp[m][n][l]!=-1)
            return dp[m][n][l];
        int one=calcone(strs[l-1]);
        int zero=calczero(strs[l-1]);
        return dp[m][n][l]=max(fun(strs,m,n,l-1),1+fun(strs,m-zero,n-one,l-1));
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        int l=strs.size();
        memset(dp,-1,sizeof(dp));
        return fun(strs,m,n,l);
    }
};
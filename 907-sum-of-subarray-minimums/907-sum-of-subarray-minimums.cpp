class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();
        stack<pair<int,int>> st;
        int m=1e9+7;
        vector<int> ng(n);
        vector<int> dp(n+1);
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                ng[i]=n;
                st.push({arr[i],i});
                continue;
            }
            while(st.size()>0&&st.top().first>=arr[i]){
                st.pop();
            }
            if(st.size()==0){
                ng[i]=n;
            }else{
                ng[i]=st.top().second;
            }
            st.push({arr[i],i});
        }
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
            dp[i]=((((ng[i]-i)%m)*(arr[i]%m))%m+dp[ng[i]])%m;
            ans=(ans%m+dp[i]%m)%m;
        }
        return ans;
    }
};
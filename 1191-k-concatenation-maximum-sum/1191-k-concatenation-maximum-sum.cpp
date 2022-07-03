class Solution {
public:
    int m=1e9+7;
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        long long int a=0;long long int b=0;long long int sa=0;long long int sb=0;
        int n=arr.size();long long int sum=0;long long int v=0;long long int ans=INT_MIN;
        for(int i=0;i<n;i++){
            sb+=arr[i]%m;
            sb=sb%m;
            sa+=arr[n-i-1]%m;
            sb=sb%m;
            a=max(a,sa);
            b=max(b,sb);
            sum+=arr[i]%m;
            sum=sum%m;
            v=max((long long int)arr[i]%m+v,(long long int)arr[i]%m);
            v=v%m;
            ans=max(ans,v);
        }
        if(k==1)
            return ans;
        ans=max(ans,max(a+b,(a+(k-2)*sum+b)));
        return ans%m;
    }
};
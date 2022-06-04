class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int n=arr.size();
        int m=1e9+7;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
            sum[i]=sum[i-1]+arr[i-1];
        }
        unordered_map<int,int> ht;int c=0;
        for(int i=0;i<=n;i++){
            int temp=sum[i]%2;
            if(temp==0)
            c=(c%m+(ht[1])%m)%m;
          else if(temp==1)
            c=(c%m+(ht[0])%m)%m;
            
            
            ht[temp]++;
        }
        return c;
        
    }
};
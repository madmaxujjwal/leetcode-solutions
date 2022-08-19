class Solution {
public:
    unordered_map<long long int,long long int> ht;
    vector< int> nums;
    unordered_map<long long int,long long int> dp;
    long long int n;
    long long int rec(int x){
        long long int ans=1;
        //if(x%2!=0)
          // return 1;
            
        if(dp.find(x)!=dp.end())
           return dp[x];
        for(auto it:ht){
            if(x%it.first==0&&ht.find(x/it.first)!=ht.end()){
                ans=ans+rec(x/it.first)*rec(it.first);
            }
           
        }
         return dp[x]=ans;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
        n=arr.size();
        nums=arr;
        long long int ans=0;
        
        for(int i=0;i<n;i++){
            ht[nums[i]]++;
        }
       // return rec(10);
        for(auto it:ht){
            ans=ans+rec(it.first);
        }
        return ans%(int)(1e9+7);
    }
};
class Solution {
public:
    unordered_map<int,int> dp;
    vector<int> num;
    int n;int ki;
    int rec(int i){
        if(i==0)return ki;
        if(i<0)return 0;
        int ans=INT_MAX;
        if(dp.find(i)!=dp.end())
            return dp[i];
        unordered_map<int,int> ht;int c=0;
        for(int j=i;j>=0;j--){
            if(ht[num[j]]==1){
                c=c+2;
            }
            else if(ht[num[j]]>1){
                c++;
            }
            ht[num[j]]++;
            ans=min(ans,ki+c+rec(j-1));
            
        }
        return dp[i]=ans;
    }
    int minCost(vector<int>& nums, int k) {
        ki=k;
        num=nums;
        n=num.size();
        
        return rec(n-1);
        
    }
};
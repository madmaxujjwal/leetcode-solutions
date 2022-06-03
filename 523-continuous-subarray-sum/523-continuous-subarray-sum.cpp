class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        if(n==1)
            return false;
        vector<int> sum(n+1,0);
        for(int i=1;i<=n;i++){
           
            sum[i]=sum[i-1]+nums[i-1];
        }
        unordered_map<int,int> ht;
        for(int i=0;i<=n;i++){
            int temp=sum[i]%k;
           
            if(ht.find(temp)!=ht.end()&&i-ht[temp]>1){
                return true;
            }
            if(ht.find(temp)==ht.end())
            ht[temp]=i;
        }
        return false;
        
    }
};
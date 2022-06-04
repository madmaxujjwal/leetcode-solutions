class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& requests) {
        int n=nums.size();
        int m=1e9+7;
        vector<long long int> rs(n,0);
        for(int i=0;i<requests.size();i++){
            rs[requests[i][0]]+=1;
            if(requests[i][1]<n-1){
                 rs[requests[i][1]+1]+=-1;
            }
        }
        for(int i=1;i<n;i++){
            rs[i]+=rs[i-1];
        }
        sort(nums.begin(),nums.end(),greater<int>());
        
        sort(rs.begin(),rs.end(),greater<int>());
        unsigned long long int ans=0;
        for(int i=0;i<n;i++){
        long long int z=nums[i];
            ans=(ans%m+(z%m*rs[i]%m)%m)%m;
        }
        return ans;
    }
};
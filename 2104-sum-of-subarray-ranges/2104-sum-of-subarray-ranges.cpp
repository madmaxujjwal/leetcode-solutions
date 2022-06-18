class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long int m=1e17+7;
        int n=nums.size();
        vector<long long int> dps(n+1);
        vector<long long int> dpg(n+1);
        dps[n]=0;
        dpg[n]=0;
        vector<long long int> ng(n);
        vector<long long int> ns(n);
        stack<pair<long long int,long long int>> stg;
        stack<pair<long long int,long long int>> sts;
        for(int i=n-1;i>=0;i--){
            if(i==n-1){
                stg.push({nums[i],i});
                sts.push({nums[i],i});
                ng[i]=n;
                ns[i]=n;
                continue;
            }
            while(stg.size()!=0&&stg.top().first<=nums[i]){
                stg.pop();
                
            }
             while(sts.size()!=0&&sts.top().first>=nums[i]){
                sts.pop();
                
            }
            if(stg.size()==0){
                ng[i]=n;
            }
            else{
                ng[i]=stg.top().second;
                
            }
            if(sts.size()==0){
                ns[i]=n;
            }
            else{
                ns[i]=sts.top().second;
                
            }
             stg.push({nums[i],i});
                sts.push({nums[i],i});
        }
        long long int ans=0;
        for(int i=n-1;i>=0;i--){
             dps[i]=((((ns[i]-i))*(nums[i]))+dps[ns[i]]);
           dpg[i]=((((ng[i]-i))*(nums[i]))+dpg[ng[i]]);
            ans=(ans+(dpg[i]-dps[i]));
        }
        return ans;
    }
};
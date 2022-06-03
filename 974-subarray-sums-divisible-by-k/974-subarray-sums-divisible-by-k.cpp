class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();int ans=0;
        vector<int> sum(n+1,0);
        unordered_map<int,int> ht;
        for(int i=1;i<=n;i++){
          //  if(nums[i-1]%k==0)ans++;
            sum[i]=sum[i-1]+nums[i-1];
        }
        
        for(int i=0;i<=n;i++){int temp;
            if(sum[i]>0)
             temp=sum[i]%k;
            else
            {double z=sum[i];
              temp=((int)ceil((abs(z))/k)*k+sum[i])%k ;}
            ans=ans+ht[temp];
           
            ht[temp]++;
        }
        return ans;
        
    }
};
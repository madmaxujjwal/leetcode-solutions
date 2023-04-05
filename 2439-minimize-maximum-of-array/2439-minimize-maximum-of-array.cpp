class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n=nums.size();
        long long int sum=nums[0];
        long long int ans=nums[0];
        
        for(int i=1;i<n;i++){
            
            if(nums[i]>ans){
                
                long long int cap=i*ans-sum;
                
                long long int z=((long long int)nums[i]-(long long int)cap-(long long int)ans)*i;
                if(z<0)z=0;
               // ans=max(ans,nums[i]-cap);
               // int z=(nums[i]-ans)*i;
               //int c=i+i;
                //int d=(14)/(3);
                long long int d= z/(1+i);
                
                ans=max({ans,(long long int)nums[i]-d-cap});
            }
            sum=sum+nums[i];
            
        }
        return ans;
    }
};
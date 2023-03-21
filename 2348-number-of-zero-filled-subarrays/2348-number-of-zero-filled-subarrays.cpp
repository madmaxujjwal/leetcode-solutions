class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        
        int n=nums.size();
       long long  int ans=0;
        long long int c=0;
        for(int i=0;i<n;i++){
            if(nums[i]==0){
                c++;
            }
            else{
                ans+=c*(c+1)/2;
                c=0;
            }
            
        }
        return ans+c*(c+1)/2;
    }
};
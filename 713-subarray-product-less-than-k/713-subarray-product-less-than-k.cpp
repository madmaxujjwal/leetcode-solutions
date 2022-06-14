class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k==0)
            return 0;
        int n=nums.size();
        int i=0;
        int j=0;
        int p=1;int ans=0;
        while(j<n){
            p=p*nums[j];
            if(p<k){
                j++;
            }
            else{
                ans+=j-i;
                p=p/nums[i];
                i++;
                if(i<=j)
                p=p/nums[j];
                else{
                    j++;
                }
                
            }
        }
        int ki=j-i;
        ans=ans+ki*(ki+1)/2;
        if(ans>0)
       return ans;
        return 0;
    }
};
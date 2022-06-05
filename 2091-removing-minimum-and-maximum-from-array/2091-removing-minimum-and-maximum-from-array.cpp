class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        int mini=nums[0];
        int maxi=nums[0];
        int a=0;
        int b=0;
        for(int i=0;i<n;i++){
            if(mini>nums[i]){
                mini=nums[i];
                a=i;
            }
            if(maxi<nums[i]){
                maxi=nums[i];
                b=i;
            }
        }
        int x=min(a,b);
        int y=max(a,b);
        int ans=min(x+1+n-y,min(y+1,n-x));
        return ans;
        
    }
};
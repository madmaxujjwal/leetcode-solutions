class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int dpmax[n];
        int dpmin[n];
        dpmax[0]=nums[0];
        dpmin[0]=nums[0];int ans=nums[0];
        for(int i=1;i<n;i++){
            int a=dpmax[i-1];
            int b=dpmin[i-1];
            int e=nums[i];
            dpmax[i]=max(a*e,max(b*e,e));
            dpmin[i]=min(a*e,min(b*e,e));
            ans=max(ans,dpmax[i]);
        }
        return ans;
    }
};
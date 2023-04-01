class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=nums[i];
        }
        sort(ans.begin(),ans.end());
       
        int in=lower_bound(ans.begin(),ans.end(),target)-ans.begin();
        if(in==n)return -1;
        if(ans[in]==target)return in;
        return -1;
    }
};
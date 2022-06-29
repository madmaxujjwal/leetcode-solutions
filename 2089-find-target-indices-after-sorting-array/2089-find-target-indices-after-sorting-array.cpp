class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int si=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int ui=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        vector<int> ans;
        for(int i=si;i<ui;i++){
            ans.push_back(i);
        }
        return ans;
    }
};
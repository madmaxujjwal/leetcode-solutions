class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        vector<int> ans;
        while(i<j){
            if(i<j){
                ans.push_back(nums[i]);
                i++;
            }
            if(i<j){
                ans.push_back(nums[j]);
                j--;
            }
        }
        
            ans.push_back(nums[n/2]);
        return ans;
    }
};
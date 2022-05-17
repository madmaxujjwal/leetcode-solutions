class Solution {
public:
    vector<int> subset;
    void rec(vector<int> nums,int i,int n,vector<vector<int>> &ans){
        if(i==n){
            ans.push_back(subset);
            return;
        }
        rec(nums,i+1,n,ans);
        subset.push_back(nums[i]);
        rec(nums,i+1,n,ans);
        subset.pop_back();
        
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        
        
        int n=nums.size();
        vector<vector<int>> ans;
        if(n==0){
            return ans;
        }
        
        rec(nums,0,n,ans);
        return ans;
    }
};
class Solution {
public:
    unordered_map<int,vector<int>> ht;
    Solution(vector<int>& nums) {
        int n =nums.size();
        for(int i=0;i<n;i++){
            ht[nums[i]].push_back(i);
        }
    }
    
    int pick(int target) {
        int n=ht[target].size();
        return ht[target][rand()%n];
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
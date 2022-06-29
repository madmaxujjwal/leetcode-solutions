class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i=i+2){
            int v=nums[i+1];
            int f=nums[i];
            while(f--){
                ans.push_back(v);
            }
        }
        return ans;
    }
};
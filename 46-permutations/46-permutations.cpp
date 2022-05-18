class Solution {
public:
    vector<vector<int>> ans;
    unordered_map<int,bool> chosen;
    vector<int> permutation;
    void search(int n,vector<int>& nums){
        if(permutation.size()==n){
            ans.push_back(permutation);
            return;
        }
        for(int i=0;i<n;i++){
            if(chosen[i]==true)
                continue;
            chosen[i]=true;
            permutation.push_back(nums[i]);
            search(n,nums);
            permutation.pop_back();
            chosen[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        search(n,nums);
        return ans;
    }
};
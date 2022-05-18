class Solution {
public:
     vector<vector<int>> ans;
    unordered_map<int,bool> chosen;
    vector<int> permutation;
    map<vector<int>,int> p;
    void search(int n,vector<int>& nums){
        if(permutation.size()==n){
            if(p.find(permutation)==p.end()){
            ans.push_back(permutation);
            p[permutation]++;
            }
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
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        search(n,nums);
        return ans;
    }
};
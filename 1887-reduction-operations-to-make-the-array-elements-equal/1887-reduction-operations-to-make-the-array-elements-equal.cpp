class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        int ans=0;int n=nums.size();
        map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[nums[i]]++;
        }
        int c=0;
        for(auto it:ht){
            ans+=c*it.second;c++;
        }
        return ans;
    }
};
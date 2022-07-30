class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> ht;
        int ans=INT_MIN;int sum=0;
        int i=0;int j=0;
        while(j<n){
            if(ht[nums[j]]==0){
                sum+=nums[j];
                ht[nums[j]]++;
                j++;
            }
            else{
                while(i<n&&nums[i]!=nums[j]){
                    ht[nums[i]]--;
                    sum-=nums[i];
                    i++;
                    
                }
                    ht[nums[i]]--;
                    sum-=nums[i];
                i++;
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};
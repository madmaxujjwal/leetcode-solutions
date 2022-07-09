class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        vector<int> in(n,0);
        sort(nums.begin(),nums.end());
        dp[0]=1;
        int maxi=1;
        int ind=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<1+dp[j])
                    {dp[i]=1+dp[j];
                     in[i]=j;
                    }
                   
                    
                }
            }
            if(maxi<dp[i]){
                maxi=dp[i];
                ind=i;
            }
        }
        vector<int> ans;
        int size=0;int i=ind;
        while(size<maxi){
            ans.push_back(nums[i]);
            size++;
            i=in[i];
        }
       
        return ans;
    }
};
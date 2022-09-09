class Solution {
public:
    unordered_map<int,int> dp;
    int rec(int x){
        if(x==0){
            return 0;
        }
        if(dp.find(x)!=dp.end()){
            return dp[x];
        }
        if(x%2!=0){
            return dp[x]= 1+rec(x/2);
        }
        return dp[x]=rec(x/2);
    }
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            if(nums[i]!=0)
            maxi=max(maxi,(int)log2(nums[i]));
        }
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+rec(nums[i]);
        }
        return sum+maxi;
    }
};
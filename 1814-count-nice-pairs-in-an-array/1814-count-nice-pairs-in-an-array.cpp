class Solution {
public:
    int m=1e9+7;
    int rev(int n){
        int rev=0;
        while(n){
            rev=rev*10+(n%10);
          
            n=n/10;
        }
        return rev;
    }
    int countNicePairs(vector<int>& nums) {
       unordered_map<int,int> ht;
        int n=nums.size();int ans=0;
        for(int i=0;i<n;i++){
            int d=nums[i]-rev(nums[i]);
            ans=(ans%m+ht[d]%m)%m;
            ht[d]++;
        }
        return ans;
    }
};
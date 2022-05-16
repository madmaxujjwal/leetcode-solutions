class Solution {
public:
    int m=1000000007;
    
    int numSubseq(vector<int>& nums, int target) {
        int n=nums.size();
        vector<int> power(100009);
        power[0]=1;
        for(int i=1;i<=100005;i++){
            power[i]=(power[i-1]*2)%m;
        }
        sort(nums.begin(),nums.end());
        int i=0;
        int j=n-1;
        int ans=0;
        while(i<=j){
            if((nums[i]+nums[j])<=target){
                ans=(ans+power[j-i]%m)%m;
                i++;
            }
            else{
                j--;
            }
        }
        return ans;
    }
};
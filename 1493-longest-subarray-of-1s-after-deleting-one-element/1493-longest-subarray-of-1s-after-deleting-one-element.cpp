class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int i=0;
        int j=0;
        int c=0;
        while(j<n){
            if(nums[j]==0){
                c++;
            }
            if(c==2){
                ans=max(ans,j-i-1);
                while(nums[i]!=0){
                    i++;
                }
                i++;
                c--;
                
            }
            else if(c==1)
             ans=max(ans,j-i);
            else
             ans=max(ans,j-i);
            
            j++;
            
        }
        return ans;
    }
};
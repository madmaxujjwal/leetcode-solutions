class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        
        int n=nums.size();
        
        int dpp[n];
        int dpn[n];
        for(int i=0;i<n;i++){
            dpp[i]=1;
            dpn[i]=1;
        }
        
        int ans=1;
        //if(n>1)ans=2;
        for(int i=1;i<n;i++){
            
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i]){
                    dpp[i]=max(dpp[i],1+dpn[j]);
                }
                else if(nums[j]>nums[i]){
                     dpn[i]=max(dpn[i],1+dpp[j]);
                }
                
            }
            ans=max(ans,dpp[i]);
            ans=max(ans,dpn[i]);
            
            
        }
        return ans;
    }
};
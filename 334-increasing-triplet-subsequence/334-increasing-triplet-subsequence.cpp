class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int n=nums.size();
        int min1=INT_MAX;
        int min2=INT_MAX;
        
        for(int i=0;i<n;i++){
            if(nums[i]<=min1){
                min1=nums[i];
               
            }
            else if(min2>nums[i]&&nums[i]>min1){
                min2=nums[i];
               
            }
            else if(nums[i]>min2){
                return true;
            }
            
            
        }return false;
    }
};
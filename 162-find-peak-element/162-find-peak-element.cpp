class Solution {
public:
    int findPeakElement(vector<int>& nums) {
         int n=nums.size();
        int i=0;
        int j=n-1;
        if(i==j)
            return i;
        if(nums[i]>nums[i+1])
            return 0;
        if(nums[j]>nums[j-1])
            return j;
         while(i<j){
             int mid=(i+j)/2;
             
             if((mid>=1)&&(mid<n)&&(nums[mid]>nums[mid-1])&&(nums[mid]>nums[mid+1]))
                 return mid;
             else if((mid>=1)&&nums[mid-1]>nums[mid]){
                 j=mid-1;
             }
             else
                 i=mid+1;
         }
        return i;
        
    }
};
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int m;
        while(l<=h){
            m=(l+h)/2;
            if(m!=0&&m!=(n-1)){
                if(nums[m-1]!=nums[m]&&nums[m]!=nums[m+1])
                    return nums[m];
                else if(nums[m-1]==nums[m]){
                    if(m%2==0){
                        h=m-2;
                    }
                    else{
                        l=m+1;
                    }
                }
                else{
                     if(m%2==0){
                        l=m+2;
                    }
                    else{
                        h=m-1;
                    }
                }
            }
            else{
                return nums[m];
            }
            
        }
        return -1;
        
    }
};
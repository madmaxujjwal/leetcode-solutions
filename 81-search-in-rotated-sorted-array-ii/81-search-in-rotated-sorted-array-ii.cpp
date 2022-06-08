class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        if(n==1){
            return nums[0]==target;
        }
        int i=0;int j=n-1;
        while(i<j){
            int m=(i+j)/2;
            if(nums[m]==target){
                return true;
            }
            else if(nums[i]!=target&&nums[j]!=target&&nums[i]==nums[j]){
                i++;
                j--;
            }
            else if(nums[i]==target||nums[j]==target){
                return true;
            }
            else if(nums[m]<nums[i]){
                if(nums[m]>target){
                    j=m-1;
                }
                else{
                    if(target>nums[j]){
                        j=m-1;
                    }else{
                        i=m+1;
                    }
                }
            }
            else{
                if(nums[m]<target){
                    i=m+1;
                }
                else{
                    if(target>nums[i]){
                        j=m-1;
                    }else{
                        i=m+1;
                    }
                }
            }
        }
        return false;
    }
};
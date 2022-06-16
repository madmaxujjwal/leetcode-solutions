class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        bool v=true;
        for(int i=0;i<n;i++){
            if(nums[i]==n){
                v=false;
            }
            if(nums[i]<0){
                nums[i]=0;
            }
            else if(nums[i]==0){
                nums[i]=-1-n;
            }
            else{
                nums[i]=0-nums[i];
            }
        }
        for(int i=0;i<n;i++){
            int a=abs(nums[i]);
            if(a<n){
                if(nums[a]==0){
                    nums[a]=5+n;
                }
                else
                nums[a]=abs(nums[a]);
            }
        }
        for(int i=1;i<n;i++){
            if(nums[i]<=0){
                return i;
            }
        }
        if(v==true)
        return n;
        return n+1;
    }
};
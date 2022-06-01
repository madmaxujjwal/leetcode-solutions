class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int tsum=0;
        for(int i=0;i<n;i++){
            tsum+=nums[i];
        }
        int s=0;
        for(int i=0;i<n;i++){
            tsum-=nums[i];
            if(s==tsum){
                return i;
            }
            s+=nums[i];
        }
        return -1;
    }
};
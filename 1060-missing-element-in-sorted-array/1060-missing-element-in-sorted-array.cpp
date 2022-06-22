class Solution {
public:
    int missingElement(vector<int>& nums, int k) {
        int n=nums.size();
        int l=0;
        int h=n-1;
        int z=nums[h]-nums[l]-h+l;
        if(z<k){
            return nums[h]+k-z;
        }
        while(l<=h){
        int m=(l+h)/2;
        int v=nums[m]-nums[l]-m+l;
        if((h-l<=1)&&(nums[h]-nums[l])>=k)
            return nums[l]+k;
        if(v>=k)
            h=m;
        else{
            k=k-v;
            l=m;
        }    
        }
        return -1;
    }
};
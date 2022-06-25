class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return true;
        int c=0;int p=-1;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i])
            { c++;
             p=i;
            }
        }
        if(c>1)
            return false;
        if(c==0){
            return true;
        }
      int a=nums[p];int b=nums[p+1];
        nums[p]=a;nums[p+1]=a;
        bool v1=true;
        bool v2=true;
        for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                v1=false;break;
            }
        }
        nums[p]=b;nums[p+1]=b;
         for(int i=0;i<n-1;i++){
            if(nums[i+1]<nums[i]){
                v2=false;break;
            }
        }
        return v1|v2;
    }
};
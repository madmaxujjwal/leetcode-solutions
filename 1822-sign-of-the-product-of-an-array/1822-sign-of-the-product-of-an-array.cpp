class Solution {
public:
    int arraySign(vector<int>& nums) {
        int z=1;
        for(auto it:nums){
            if(it==0)
                return 0;
            else if(it<0)
                z=0-z;
        }
        return z;
    }
};
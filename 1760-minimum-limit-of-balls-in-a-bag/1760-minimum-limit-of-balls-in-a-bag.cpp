class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int l=1;
        int h=*max_element(nums.begin(),nums.end());
        while(l<=h){
            int m=(l+h)/2;
            bool v=true;int val=0;
            for(int i=0;i<n;i++){
                val=val+ceil((double)nums[i]/m)-1;
                if(val>maxOperations){
                    v=false;
                    break;
                }
            }
            if(v){
                h=m-1;
            }
            else{
                l=m+1;
            }
            
        }
        return l;
    }
};
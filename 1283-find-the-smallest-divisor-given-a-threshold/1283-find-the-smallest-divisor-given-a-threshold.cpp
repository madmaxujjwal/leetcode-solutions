class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        int l=1;
        int h=1000000;
        while(l<=h){
            int m=(l+h)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+ceil((double)nums[i]/m);
            }
            if(sum<=threshold){
                h=m-1;
            }
            else{
                l=m+1;
            }
            
            
        }
        return l;
    }
};
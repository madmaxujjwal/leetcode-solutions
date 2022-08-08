class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        int count=0;
        for(int i=0;i<n;i++){
            count+=nums[i];
        }
        if(count==n||count==0){
            return 0;
        }
        for(int i=0;i<n;i++){
            nums.push_back(nums[i]);
        }
        int c=0;int i=0;int j=0;
        int ans=INT_MAX;
        while(j<2*n){
            
            if(nums[j]==0){
                c++;
            }
            if(j-i+1<count){
                
            }
            else{
                ans=min(ans,c);
                if(nums[i]==0){
                    c--;
                }
                i++;
                
            }
            j++;
        }
        return ans;
    }
};
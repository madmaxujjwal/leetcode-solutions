class Solution {
    public int[] sumEvenAfterQueries(int[] nums, int[][] queries) {
        
        int n=nums.length;
        int sum=0;
        for(int i=0;i<n;i++){
            if(nums[i]%2==0){
                sum=sum+nums[i];
            }
        }
        int m=queries.length;
        int ans[]=new int[m];
        for(int i=0;i<m;i++){
            int ind=queries[i][1];
            int val=queries[i][0];
            if((nums[ind]+val)%2==0){
                if(nums[ind]%2==0){
                    sum=sum+val;
                }
                else{
                    sum=sum+nums[ind]+val;
                }
            }
            else{
                 if(nums[ind]%2==0){
                    sum=sum-nums[ind];
                }
               
            }
            nums[ind]+=val;
            ans[i]=sum;
        }
        return ans;
    }
}
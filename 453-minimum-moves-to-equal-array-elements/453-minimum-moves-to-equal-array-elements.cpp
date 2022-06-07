class Solution {
public:
    int minMoves(vector<int>& nums) {
     int n=nums.size();
     sort(nums.begin(),nums.end());
     unsigned long long int sum=0;
     int d=nums[n-1]-nums[0];
       sum=d;
        for(int i=1;i<n;i++){
            sum=sum-i*(nums[i]-nums[i-1])+d;
        }
        
        return sum;
    }
};
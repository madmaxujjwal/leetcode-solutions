class Solution {
public:
    int maximumProduct(vector<int>& nums, int k) {
        int m=1e9+7;
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> minh;
        for(int i=0;i<n;i++){
            minh.push(nums[i]);
        }
        int c=0;
        while(c<k){
            int t=minh.top();
            minh.pop();
            t++;
            minh.push(t);
            c++;
        }
      unsigned long long int ans=1;
        while(minh.size()!=0){
            ans=(ans%m*minh.top()%m)%m;
            minh.pop();
    }
        return ans;}
};
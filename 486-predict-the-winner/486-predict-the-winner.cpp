class Solution {
public:
    int dp[21][21];
    vector<int> arr;
    int rec(int i,int j){
        if(i>j){
            return 0;
        }
        if(i==j){
            return arr[i];
        }
        if(dp[i][j]!=-1)
            return dp[i][j];
        return dp[i][j]=max(arr[i]+min(rec(i+2,j),rec(i+1,j-1)),arr[j]+min(rec(i,j-2),rec(i+1,j-1)));
    }
    bool PredictTheWinner(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        arr=nums;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)
            sum+=nums[i];
        int sca=rec(0,n-1);
        if(2*sca>=sum){
            return true;
        }
        return false;
    }
};
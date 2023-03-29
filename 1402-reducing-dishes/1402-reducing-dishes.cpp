class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n=satisfaction.size();
        sort(satisfaction.begin(),satisfaction.end());
        int sum=0;int ans=0;int s=0;
        for(int i=n-1;i>=0;i--){
            sum=sum+satisfaction[i]+s;
            s=s+satisfaction[i];
            ans=max(ans,sum);
        }
        return ans;
    }
};
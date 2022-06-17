class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int n=satisfaction.size();
        int v=0;int sum=0;
        for(int i=0;i<n;i++){
            sum+=satisfaction[i];
            v+=(i+1)*satisfaction[i];
        }
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,v);
            v=v-sum;
            sum=sum-satisfaction[i];
        }
        return maxi;
    }
};
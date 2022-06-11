class Solution {
public:
    long long minimumRemoval(vector<int>& beans) {
        long long int n=beans.size();
        long long int x=1000000000000000;
        sort(beans.begin(),beans.end());long long int sum=0;
        for(int i=0;i<n;i++)
            sum+=beans[i];
        for(int i=0;i<n;i++){
            x=min(x,sum-(n-i)*beans[i]);
        }
        return x;
    }
};
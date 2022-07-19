class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        int l=1;
        int h=*max_element(candies.begin(),candies.end());
        while(l<=h){
            int m=(l+h)/2;
           long long int sum=0;
            for(int i=0;i<n;i++){
                sum=sum+candies[i]/m;
            }
            if(sum>=k){
                l=m+1;
            }
            else
                h=m-1;
        }
        return l-1;
    }
};
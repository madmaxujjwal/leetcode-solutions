class Solution {
public:
    int minimumLines(vector<vector<int>>& stockPrices) {
        sort(stockPrices.begin(),stockPrices.end());
       long long int c=0;
        long long int n=stockPrices.size();
       long double m;
        long double z=INT_MIN;int ans=0;
        for(int i=1;i<n;i++){
            if((stockPrices[i-1][0]-stockPrices[i][0]!=0))
            {  m=((long double)stockPrices[i-1][1]-(long double)stockPrices[i][1])/((long double)stockPrices[i-1][0]-(long double)stockPrices[i][0]) ;}
            else
               m=INT_MAX;
            if(m!=z){
                ans++;
            }   
               z=m;
        }
    
               return ans;
}
               };
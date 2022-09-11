class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
       
        int n=candies.size(); vector<bool> ans(n);
        for(int i=0;i<n;i++){
            int maxi=INT_MIN;
            for(int j=0;j<n;j++){
                
                if(i!=j){
                    maxi=max(maxi,candies[j]);
                }
                
            }
            
            if(candies[i]+extraCandies>=maxi){
                ans[i]=true;
            }
            else
                ans[i]=false;
        }
        return ans;
    }
};
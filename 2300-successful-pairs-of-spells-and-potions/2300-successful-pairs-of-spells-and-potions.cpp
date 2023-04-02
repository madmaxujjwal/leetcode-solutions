class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        int n=potions.size();
        vector<int> ans(spells.size());
        for(int i=0;i<spells.size();i++){
            double k=success;
            
            long long int v=ceil(k/spells[i]);
            int in=n-(lower_bound(potions.begin(),potions.end(),v)-potions.begin());
            ans[i]=in;
            
            
        }
        return ans;
    }
};
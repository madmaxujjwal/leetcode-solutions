class Solution {
public:
    int beautySum(string s) {
        int n=s.size();unordered_map<char,long long int> ht;
      long long int ans=0;
        for(int i=0;i<n;i++){
             
            for(int j=i;j<n;j++){
               long long int maxi=0;long long int mini=1000;
                ht[s[j]]++;
                for(auto it:ht){
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                ans+=maxi-mini;
                
            }
              
                ht.clear();
                
                
                 }
        return ans;
    }
};
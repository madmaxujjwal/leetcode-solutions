class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int n=s.size();
        int m=p.size();
        unordered_map<char,int> ht;
        unordered_map<char,int> ht1;
        int i=0;
        int j=0;
        for(int i=0;i<m;i++){
            ht[p[i]]++;
        }
        while(j<n){
            ht1[s[j]]++;
            if(j-i+1<m){
                j++;
            }
            else{
                if(ht==ht1)
                {
                    ans.push_back(i);
                    
                }
                j++;
                ht1[s[i]]--;
                if(ht1[s[i]]==0)
                    ht1.erase(s[i]);
                i++;
            }
        }
        return ans;
    }
};
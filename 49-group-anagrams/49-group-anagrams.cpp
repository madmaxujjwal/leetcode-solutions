class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,int> ht;int c=0;
        for(int i=0;i<strs.size();i++){
            string z=strs[i];
            sort(z.begin(),z.end());
            if(ht.find(z)==ht.end())
            { ht[z]=c;
               
            c++;}
        }
        vector<vector<string>> ans(c);
        for(int i=0;i<strs.size();i++){
             string z=strs[i];
            sort(z.begin(),z.end());
            ans[ht[z]].push_back(strs[i]);
        }
        
        return ans;
    }
};
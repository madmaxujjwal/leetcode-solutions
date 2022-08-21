class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string> ans;
        int n=words.size();
        unordered_map<char,char> ht;
        unordered_map<char,char> ht1;
        for(int i=0;i<n;i++){
            
            string z=pattern;bool v=true;
            if(words[i].size()!=pattern.size())
                continue;
            for(int j=0;j<z.size();j++){
                if(ht.find(z[j])!=ht.end()&&ht[z[j]]!=words[i][j]){
                    v=false;
                }
                if(ht1.find(words[i][j])!=ht1.end()&&ht1[words[i][j]]!=z[j]){
                    v=false;
                }
                
                ht[z[j]]=words[i][j];
                ht1[words[i][j]]= z[j];
                
                
            }
            if(v)
            ans.push_back(words[i]);
            ht.clear();
            ht1.clear();
        }
        return ans;
    }
};
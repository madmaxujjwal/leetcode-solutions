class Solution {
public:
    bool rec(string s,unordered_map<string,int> &ht,unordered_map<string,int> &dp){
        if(dp.find(s)!=dp.end())
            return dp[s];
        if(s.size()==0)
            return true;
        string z="";
        for(int i=0;i<s.size();i++){
            z+=s[i];
            if(ht.find(z)!=ht.end()&&rec(s.substr(i+1),ht,dp))
                return dp[s]=true;
        }
        return dp[s]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.size();
        unordered_map<string,int> ht;
        for(int i=0;i<wordDict.size();i++){
            ht[wordDict[i]]++;
        }
        unordered_map<string,int> dp;
        return rec(s,ht,dp);
    }
};
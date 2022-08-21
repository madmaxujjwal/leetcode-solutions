class Solution {
public:
    
    bool check(string a,string b){
        if((a.size()+1)!=b.size())
            return false;
       
        for(int i=0;i<a.size();i++){
            if((a[i]!=b[i])&&a[i]!=b[i+1]){
                return false;
                
            }
           
        } return true;
    }
    static bool sortbylen(string &a,string& b){
        return a.size()<b.size();
    }
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),sortbylen);
        unordered_map<string,int> ht;
        ht[words[0]]=0;
     //  return check(words[3],words[4]);
        int n=words.size();
        vector<int> dp(n,1);int ans=1;
        for(int i=1;i<n;i++){
           for(int j=0;j<words[i].size();j++){
               string v=words[i].substr(0,j)+words[i].substr(j+1);
               if(ht.find(v)!=ht.end()){
                   dp[i]=max(dp[i],1+dp[ht[v]]);
               }
           }
            ht[words[i]]=i;
            ans=max(ans,dp[i]);
        }
        
        return ans;
        
    }
};
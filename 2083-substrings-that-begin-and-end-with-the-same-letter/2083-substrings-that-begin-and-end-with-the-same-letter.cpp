class Solution {
public:
    long long numberOfSubstrings(string s) {
        int n=s.size();
        long long int ans=0;
        unordered_map<char,int> ht;
        for(int i=0;i<n;i++){
            ht[s[i]]++;
        }
        for(int j=n-1;j>=0;j--){
            ans+=ht[s[j]];
            ht[s[j]]--;
        }
        return ans;
    }
};
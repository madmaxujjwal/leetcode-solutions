class Solution {
public:
    int minSteps(string s, string t) {
        unordered_map<char,int> ht1;
        unordered_map<char,int> ht2;
        for(auto it:s){
            ht1[it]++;
        }
        for(auto it:t){
            ht2[it]++;
        }
        int ans=0;
        for(char ch='a';ch<='z';ch++){
            ans+=max(0,ht2[ch]-ht1[ch]);
        }
        for(char ch='a';ch<='z';ch++){
            ans+=max(0,ht1[ch]-ht2[ch]);
        }
        return ans;
    }
};
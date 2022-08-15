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
        for(auto it:ht1){
            ans+=max(0,it.second-ht2[it.first]);
        }
        return ans;
    }
};
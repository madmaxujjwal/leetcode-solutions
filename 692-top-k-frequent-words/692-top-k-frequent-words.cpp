class Solution {
public:
    
   static bool compe(pair<int,string> &a,pair<int,string> &b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int,greater<string>> ht;
         priority_queue< pair<int,string>,vector< pair<int,string>>,greater< pair<int,string>>> minh;
        int n=words.size();
        for(int i=0;i<n;i++){
            ht[words[i]]++;
            
        }
        vector<pair<int,string>> z;
        for(auto it:ht){
            z.push_back({it.second,it.first});
        }
        vector<string> ans(k);
        sort(z.begin(),z.end(),compe);
       n=z.size();
        for(int i=0;i<k;i++){
            ans[i]=z[i].second;
        }
        return ans;
    }
};
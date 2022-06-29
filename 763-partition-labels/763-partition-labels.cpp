class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> ans;
        int n=s.size();
        unordered_map<char,int> ht;
        for(int i=0;i<n;i++){
            ht[s[i]]=i;
        }
        int e=-1;int st=0;
        for(int i=0;i<n;i++){
            e=max(e,ht[s[i]]);
            if(i==e){
                ans.push_back(e-st+1);
                st=i+1;
                e=-1;
            }
            
        }
        return ans;
    }
};
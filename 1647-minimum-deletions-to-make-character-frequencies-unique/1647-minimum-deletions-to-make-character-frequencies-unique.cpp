class Solution {
public:
    int minDeletions(string s) {
        int n=s.size();
        unordered_map<char,int> ht;
        for(int i=0;i<n;i++){
            ht[s[i]]++;
        }
        vector<int> z;
        for(auto it:ht){
            z.push_back(it.second);
        }
        sort(z.begin(),z.end(),greater<int>());
        n=z.size();int c=0;
        for(int i=1;i<n;i++){
            if(z[i-1]==0){
                c=c+z[i];
                z[i]=0;continue;
            }
            if(z[i]>=z[i-1]){
                int temp=z[i];
                z[i]=z[i-1]-1;
                c=c+temp-z[i];
            }
        }
        return c;
    }
};
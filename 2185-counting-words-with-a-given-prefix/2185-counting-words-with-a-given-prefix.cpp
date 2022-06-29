class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int c=0;
        int n=words.size();int f=pref.size();
        for(int i=0;i<n;i++){
            if(pref==words[i].substr(0,f))
                c++;
        }
        return c;
    }
};
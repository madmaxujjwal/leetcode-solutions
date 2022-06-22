class Solution {
public:
    
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int ans=INT_MAX;
       
        int n=wordsDict.size();
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++){
            if(wordsDict[i]==word1)
                a.push_back(i);
            if(wordsDict[i]==word2)
                b.push_back(i);
        }
         n=a.size();
        int m=b.size();
        int i=0;int j=0;
        while(i<n&&j<m){
            if(a[i]!=b[j])
            ans=min(ans,abs(a[i]-b[j]));
            if(a[i]==b[j]){
                i++;
                continue;
            }
            if(a[i]>b[j]){
                j++;
            }
            else
                i++;
        }
        return ans;
    }
};
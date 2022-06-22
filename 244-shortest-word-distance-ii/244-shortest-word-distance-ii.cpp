class WordDistance {
public:
    vector<string> w;
    int n;
    unordered_map<string,vector<int>> ht;
    WordDistance(vector<string>& wordsDict) {
        w=wordsDict;
        n=wordsDict.size();
        for(int i=0;i<n;i++){
            ht[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
      
        int mini=INT_MAX;
        vector<int> a=ht[word1];
        vector<int> b=ht[word2];
        int n=a.size();
        int m=b.size();
        int i=0;
        int j=0;
        while(i<n&&j<m){
            mini=min(mini,abs(a[i]-b[j]));
            if(a[i]>b[j]){
                j++;
            }
            else
                i++;
        }
        return mini;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */
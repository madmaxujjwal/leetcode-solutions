class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> present;
        unordered_map<string,int> visited;
        for(int i=0;i<wordList.size();i++){
            present[wordList[i]]++;
        }
        vector<char> g;
        for(char ch='a';ch<='z';ch++){
            g.push_back(ch);
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        visited[beginWord]++;
        while(q.size()>0){
            string str=q.front().first;
            int level=q.front().second;
            q.pop();
            if(str==endWord)
                return level;
            for(int i=0;i<beginWord.size();i++){
                string temp=str;
                for(int j=0;j<26;j++){
                    string t=temp;
                    t[i]=g[j];
                    if(present[t]>0&&visited[t]==0){
                        q.push({t,level+1});
                        visited[t]++;
                    }
                }
            }
            
            
        }
        return 0;
    }
};
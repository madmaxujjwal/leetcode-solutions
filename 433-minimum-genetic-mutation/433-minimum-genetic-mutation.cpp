class Solution {
public:
    int minMutation(string start, string end, vector<string>& bank) {
       unordered_map<string,bool> visited;
       unordered_map<string,int> present;
       char g[]={'A','C','G','T'};
        for(int i=0;i<bank.size();i++){
            present[bank[i]]++;
        }
        visited[start]=true;
        queue<pair<string,int>> q;
        q.push({start,0});
        while(q.size()>0){
            if(q.front().first==end){
                return q.front().second;
            }
              string t=q.front().first;
              int l=q.front().second;
                q.pop();
            for(int i=0;i<8;i++){
          string temp=t;
            for(int j=0;j<4;j++){
                temp[i]=g[j];
                if(visited[temp]!=true&&present[temp]>0){
                    visited[temp]=true;
                    q.push({temp,l+1});
                }
            }
            
        }
        }
        return -1;
    }
};
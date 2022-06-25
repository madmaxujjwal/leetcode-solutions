class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    void make_set(int a){
        parent[a]=a;
        size[a]=1;
    }
    int find_set(int a){
        if(a==parent[a])
            return a;
        return parent[a]=find_set(parent[a]);
    }
    void make_union(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(a==b)
            return;
        if(a>b)
            swap(a,b);
        parent[b]=a;
        size[a]+=b;
        
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n=s.size();
        for(int i=0;i<n;i++)
            make_set(i);
        for(int i=0;i<pairs.size();i++){
            make_union(pairs[i][0],pairs[i][1]);
        }
         for(int i=0;i<pairs.size();i++){
            make_union(pairs[i][0],pairs[i][1]);
        }
        unordered_map<int,priority_queue<char,vector<char>,greater<char>>> v;
        for(int i=0;i<n;i++){
            int p=parent[i];
            v[p].push(s[i]);
        }
        string ans="";
        for(int i=0;i<n;i++){
              int p=parent[i];
            char ch=v[p].top();
              ans+=ch;
            v[p].pop();
        }
        return ans;
    }
};
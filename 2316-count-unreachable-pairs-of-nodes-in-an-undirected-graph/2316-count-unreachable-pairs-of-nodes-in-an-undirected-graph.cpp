class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    void make_set(int x){
        parent[x]=x;
        size[x]=1;
    }
    int find_set(int x){
        if(x==parent[x])
            return x;
        return parent[x]=find_set(parent[x]);
    }
    void make_union(int x,int y){
        x=find_set(x);
        y=find_set(y);
        if(x!=y){
            if(size[x]<size[y]){
                swap(x,y);
            }
            parent[y]=x;
            size[x]+=size[y];        
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        
        for(int i=0;i<n;i++){
            make_set(i);
        }
        for(int i=0;i<edges.size();i++){
            make_union(edges[i][0],edges[i][1]);
        }
         for(int i=0;i<edges.size();i++){
            make_union(edges[i][0],edges[i][1]);
        }
        unordered_map<int,int> ht;
        for(int i=0;i<n;i++){
            ht[parent[i]]=size[parent[i]];
        }
        vector<long long int> ans;long long int sum=0;
        for(auto it:ht){
            ans.push_back(it.second);
            sum+=it.second;
        }
        n=ans.size();
        long long int v=0;
        for(int i=0;i<n;i++){
            sum-=ans[i];
            v=v+ans[i]*sum;
        }
        return v;
        
        
        
        
    }
};
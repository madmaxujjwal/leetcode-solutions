class Solution {
public:
    unordered_map<int,int> parent;
    unordered_map<int,int> size;
    void make_set(int a){
        parent[a]=a;
        size[a]=1;
    }
    int find_parent(int a){
        if(a==parent[a]){
            return a;
        }
        return parent[a]=find_parent(parent[a]);
    }
    void make_union(int a,int b){
        a=find_parent(a);
        b=find_parent(b);
        if(a!=b){
            if(size[a]<size[b]){
                swap(a,b);
            }
            parent[b]=a;
            size[a]+=size[b];
        }
    }
    static bool comp(vector<int> &a,vector<int> &b){
        return a[2]<b[2];
    }
    int minimumCost(int n, vector<vector<int>>& connections) {
        sort(connections.begin(),connections.end(),comp);
        int ans=0;
        for(int i=1;i<=n;i++){
            make_set(i);
        }
        for(int i=0;i<connections.size();i++){
           if(find_parent(connections[i][0])!=find_parent(connections[i][1])){
               ans+=connections[i][2];
               make_union(connections[i][0],connections[i][1]);
           }
            
        }
        for(int i=1;i<=n;i++){
            if(size[i]==n){
                return ans;
            }
        }
        return -1;
    }
};
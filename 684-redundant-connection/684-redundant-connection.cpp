class Solution {
public:
    int n;
    vector<int> size;
    vector<int> parent;
    void make_set(int a){
        parent[a]=a;
        size[a]=1;
    }
    int find_set(int a){
        if(a==parent[a]){
            return a;
        }
        return parent[a]=find_set(parent[a]);
    }
    void make_union(int a,int b){
        a=find_set(a);
        b=find_set(b);
        if(size[a]<size[b]){
            swap(a,b);
        }
        parent[b]=a;
        size[a]+=size[b];
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        //sort(edges.begin(),edges.end());
        n=edges.size();
        vector<int> ans;
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=1;i<=n;i++){
            make_set(i);
        }
        for(int i=0;i<n;i++){
            int a=edges[i][0];
            int b=edges[i][1];
            int x=find_set(a);
            int y=find_set(b);
            if(x==y){
                ans.push_back(a);
                ans.push_back(b);
               break;
            }
            else{
                make_union(a,b);
            }
        }
        return ans;
    }
};
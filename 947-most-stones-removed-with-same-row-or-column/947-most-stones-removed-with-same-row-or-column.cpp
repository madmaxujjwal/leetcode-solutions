class Solution {
public:
    int n;
    map<vector<int>,vector<int>> parent;
     map<vector<int>,int> size;
    void make_set(vector<int> x){
        parent[x]=x;
        size[x]=1;
    }
    vector<int> find_set(vector<int> a)
    {
        if(a==parent[a]){
            return a;
        }
        return parent[a]=find_set(parent[a]);
    }    
    void make_union(vector<int> x,vector<int> y){
        
        x=find_set(x);
        y=find_set(y);
        if(x!=y){
        if(size[x]<size[y]){
            swap(x,y);
        }
       
        size[x]+=size[y];
         parent[y]=x;
        }
    }
    
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
       
        unordered_map<int,vector<vector<int>>> rows;
        unordered_map<int,vector<vector<int>>> columns;
        for(int i=0;i<n;i++){
            make_set(stones[i]);
            int a=stones[i][0];int b=stones[i][1];
            rows[a].push_back({a,b});
            columns[b].push_back({a,b});
        }
        for(auto it:rows){
            vector<int> f=*(it.second.begin());
            for(auto i:it.second){
                make_union(i,f);
            }
        }
        
        
         for(auto it:columns){
           vector<int> f=*it.second.begin();
            for(auto i:it.second){
                make_union(i,f);
            }
        }
          for(auto it:rows){
            vector<int> f=*(it.second.begin());
            for(auto i:it.second){
                make_union(i,f);
            }
        }
        
         for(auto it:columns){
           vector<int> f=*it.second.begin();
            for(auto i:it.second){
                make_union(i,f);
            }
        }
        set<vector<int>> st;
        for(auto it:parent){
            st.insert(it.second);
        }
        
        int ans=0;
        for(auto it:st){
            ans=ans+size[it]-1;
        }
      //  vector<int> t= parent[{1,2}];
        return ans;// t[0]+t[1];
    }
};
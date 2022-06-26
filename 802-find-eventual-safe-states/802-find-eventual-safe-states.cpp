class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> ans;
        vector<int> id(n);
        vector<vector<int>> g(n);
      
        
        for(int i=0;i<n;i++){
            for(auto it:graph[i]){
                id[i]++;
                g[it].push_back(i);
            }
        }
    //    return {id[5]};
        queue<int> q;
        for(int i=0;i<n;i++){
            if(id[i]==0){
                q.push(i);
            }
        }
        while(q.size()){
            int v=q.front();
            ans.push_back(v);
            for(auto it:g[v]){
                id[it]--;
                if(id[it]==0)
                    q.push(it);
            }
            q.pop();
            
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};
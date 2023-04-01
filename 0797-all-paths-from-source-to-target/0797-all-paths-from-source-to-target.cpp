class Solution {
public:
    vector<vector<int>> adj;
    vector<vector<int>> ans;
    int n;
   void rec(int i,vector<int> &a){
        
       if(i==n-1){
           ans.push_back(a);
           return ;
       }
       
        for(auto it:adj[i]){
            
            a.push_back(it);
            rec(it,a);
            a.pop_back();
        }
        
        
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        
        adj=graph;
        vector<int> a;
        a.push_back(0);
        n=graph.size();
        rec(0,a);
        return ans;
    }
};
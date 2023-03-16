class Solution {
public:
    
    void dfs(int x, vector<int> &indegree,vector<bool> &removed,vector<vector<int>>& adj){
         removed[x]=true;
        for(auto it:adj[x]){
           
            indegree[it]--;
            if(indegree[it]==0&&removed[it]==false){
               
                dfs(it,indegree,removed,adj);
            }
        }
        return;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n);
        vector<bool> removed(n,false);
        vector<int> indegree(n,0);
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indegree[prerequisites[i][0]]++;
        }
        // if(indegree[4]==0)return true;
        // if(adj[4].size()==2)return true;
        for(int i=0;i<n;i++){
            if(indegree[i]==0&&removed[i]==false){
                dfs(i,indegree,removed,adj);
            }
        }

        for(int i=0;i<n;i++){
            if(removed[i]==false){
                return false;
            }
        }
        
        return true;
        
        
        
    }
};
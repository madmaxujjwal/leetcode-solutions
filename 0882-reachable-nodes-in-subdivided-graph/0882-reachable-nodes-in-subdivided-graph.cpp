class Solution {
public:
    int reachableNodes(vector<vector<int>>& edges, int maxMoves, int n) {
        
        vector<int> dis(n,INT_MAX);
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]+1});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]+1});
            
        }
        vector<bool> vis(n,false);
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        pq.push({0,0});
        dis[0]=0;
        while(pq.size()>0){
            int d=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            vis[x]=false;
            for(auto it:adj[x]){
                
                if(d+it.second<dis[it.first]){
                    dis[it.first]=d+it.second;
                    pq.push({d+it.second,it.first});
                }
                
            }
            
        }
        int ans=0;
        for(int i=0;i<n;i++){
            if(dis[i]<=maxMoves){
                ans++;
            }
        }
        for(int i=0;i<edges.size();i++){
            
            int a=edges[i][0];
            int b=edges[i][1];
            int x=max(0,maxMoves-dis[a]);
            int y=max(0,maxMoves-dis[b]);
            ans=ans+min(x+y,edges[i][2]);
        }
        return ans;
    }
};
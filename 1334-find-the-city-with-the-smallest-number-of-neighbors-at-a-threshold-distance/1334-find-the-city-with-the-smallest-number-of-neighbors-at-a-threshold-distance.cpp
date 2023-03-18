class Solution {
public:
    int th;
    int dijastra(int i,int n,vector<vector<pair<int,int>>> &adj){
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dis(n,INT_MAX);
        vector<bool> vis(n,false);
        pq.push({0,i});
        while(pq.size()>0){
            
            int x=pq.top().second;
            int d=pq.top().first;
            vis[x]=true;
            pq.pop();
            for(auto it:adj[x]){
                
                if(vis[it.first]==false&&d+it.second<dis[it.first]){
                    dis[it.first]=d+it.second;
                    pq.push({dis[it.first],it.first});
                }
            }
            
            
        }
        int ans=0;
        for(int j=0;j<n;j++){
            if(i!=j){
                
                if(dis[j]<=th){
                    ans++;
                }
            }
        }
        return ans;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> adj(n);
        th=distanceThreshold;
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
            
        }
        int ans=-1;
        int d=INT_MAX;
        for(int i=n-1;i>=0;i--){
            int sd=dijastra(i,n,adj);
            if(d>sd){
                d=sd;
                ans=i;
            }
            
        }
        return ans;
    }
};
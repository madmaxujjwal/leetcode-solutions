class Solution {
public:
    
    int dijastra(int k, vector<vector<pair<int,int>>> &adj,vector<int> &sd,vector<bool> &vis){
        
        priority_queue<pair<int,int> ,vector<pair<int,int> >,greater<pair<int,int> >> pq;
        pq.push({0,k-1});
        while(pq.size()>0){
            int s=pq.top().second;
            int d=pq.top().first;
            vis[s]=true;
            pq.pop();
            for(auto it:adj[s]){
                if(vis[it.first]==false){
                if(d+it.second<sd[it.first]){
                    sd[it.first]=d+it.second;
                    pq.push({sd[it.first],it.first});
                }
            }
            }
            
            
        }
        int ans=0;
        for(int i=0;i<sd.size();i++){
            if(vis[i]==false)return -1;
            if(sd[i]!=INT_MAX)
            ans=max(ans,sd[i]);
        }
        return ans;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        int m=times.size();
        vector<vector<pair<int,int>>> adj(n);
        vector<bool> vis(n,false);
        // vis[k-1]=true;
        vector<int> sd(n,INT_MAX);
        for(int i=0;i<m;i++){
            adj[times[i][0]-1].push_back({times[i][1]-1,times[i][2]});
        }
        return dijastra(k,adj,sd,vis);
    }
};
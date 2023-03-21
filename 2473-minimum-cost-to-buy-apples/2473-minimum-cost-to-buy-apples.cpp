class Solution {
public:
    
    void dijastra(long long int s,vector<vector<long long int>> &dis,vector<vector<pair<long long int,long long int>>> adj){
        int n=dis.size();
        vector<bool> vis(n,false);
        
        priority_queue<pair<long long int,long long int>,vector<pair<long long int,long long int>>,greater<pair<long long int,long long int>>> pq;
        pq.push({0,s});
        while(pq.size()>0){
            int x=pq.top().second;
            int d=pq.top().first;
            vis[x]=true;
            pq.pop();
            for(auto it:adj[x]){
                if(vis[it.first]==false&&d+it.second<dis[s][it.first]){
                    dis[s][it.first]=d+it.second;
                    pq.push({d+it.second,it.first});
                }
            }
        }
        
        
        
        
        
    }
    
    
    
    vector<long long> minCost(int n, vector<vector<int>>& roads, vector<int>& appleCost, int k) {
        
        vector<vector<long long int>> dis(n,vector<long long int>(n,INT_MAX));
        vector<vector<pair<long long int,long long int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]-1].push_back({roads[i][1]-1,roads[i][2]});
            adj[roads[i][1]-1].push_back({roads[i][0]-1,roads[i][2]});
        }
        for(int i=0;i<n;i++){
            dijastra(i,dis,adj);
        }
        vector<long long int> ans(n);
        for(int i=0;i<n;i++){
            ans[i]=appleCost[i];
        }
        for(int i=0;i<n;i++){
            
            
            for(int j=0;j<n;j++){
                
                if(i!=j){
                    
                    ans[i]=min((long long int)ans[i],(long long int)(appleCost[j]+dis[i][j]*(k+1)));
                }
                
            }
        }
        
        
        return ans;
        
        
    }
};
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        
        vector<vector<pair<int,double>>> adj(n);
       
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back({(int)edges[i][1],(double)succProb[i]});
            adj[edges[i][1]].push_back({(int)edges[i][0],(double)succProb[i]});
            
        }
       
    priority_queue<pair<double,int>> pq;
        
        pq.push({1.0,start});
        vector<bool> vis(n,false);
        vector<double> prob(n,0);
        prob[start]=1;
        
        while(pq.size()>0){
            double p=pq.top().first;
            int x=pq.top().second;
            pq.pop();
            vis[x]=true;
            for(auto it:adj[x]){
                double np=p*it.second;
                if(vis[it.first]==false&&(double)((double)p*(double)it.second)>prob[it.first]){
                    prob[it.first]=np;
                    pq.push({np,it.first});
                    
                }
            }
            
            
        }
        
        return prob[end];
    }
};
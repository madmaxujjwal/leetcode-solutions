class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        vector<vector<int>> adj(n);
        vector<int> ind(n,0);
        for(int i=0;i<relations.size();i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
            ind[relations[i][1]-1]++;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            if(ind[i]==0){
                q.push({i,1});
            }
        }
        int ans=-1;
        while(q.size()>0){
            
            int i=q.front().first;
            int l=q.front().second;
            ans=max(ans,l);
            q.pop();
            for(auto it:adj[i]){
                ind[it]--;
                if(ind[it]==0){
                    q.push({it,l+1});
                }
            }
            
        }
        for(int i=0;i<n;i++){
            if(ind[i]!=0)return -1;
        }
        return ans;
    }
};
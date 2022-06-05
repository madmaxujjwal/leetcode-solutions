class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n=costs.size();
        vector<pair<int,pair<int,int>>> z;
        for(int i=0;i<n;i++){
            z.push_back({costs[i][0]-costs[i][1],{costs[i][0],costs[i][1]}});
        }
        sort(z.begin(),z.end());
        int c=0;
        for(int i=0;i<n/2;i++){
            c=c+z[i].second.first;
        }
        for(int i=n/2;i<n;i++){
             c=c+z[i].second.second;
        }
        return c;
        
    }
};
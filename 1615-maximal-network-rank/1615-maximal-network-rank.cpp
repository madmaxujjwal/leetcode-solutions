class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,int> ht;
        map<pair<int,int>,int> con;
        for(int i=0;i<roads.size();i++){
            ht[roads[i][0]]++;
            ht[roads[i][1]]++;
           con[{roads[i][0],roads[i][1]}]++;
        }
        int maxi=0;int c;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                 c=0;
                if(con.find({i,j})!=con.end()||con.find({j,i})!=con.end())
                    c=1;
                maxi=max(maxi,ht[i]+ht[j]-c);
                
            }
        }
        
        return maxi;
    }
};
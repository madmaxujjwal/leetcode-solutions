class Solution {
public:
    int maxPoints(vector<vector<int>>& p) {
        sort(p.begin(),p.end());
        unordered_map<double,int>m;
        int ans = 0;
        for(int i = 0;i<p.size();i++){
            for(int j = i+1;j<p.size();j++){
            double tan = (p[i][1]-p[j][1])/double(p[i][0]-p[j][0]);
            m[tan]++;
            ans = max(ans,m[tan]);
            }
            m.clear();
        }
        return  ans+1;
    }
    
};
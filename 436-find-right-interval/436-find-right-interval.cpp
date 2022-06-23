class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<pair<int,int>,int>> z;
        int n=intervals.size();
        for(int i=0;i<n;i++){
            z.push_back({{intervals[i][0],intervals[i][1]},i});
        }
        sort(z.begin(),z.end());
        vector<int> k;
        vector<int> ans(n);
        for(int i=0;i<n;i++)
            k.push_back(z[i].first.first);
        for(int i=0;i<n;i++){
            int temp=z[i].first.second;
            int it=z[i].second;
            int index=lower_bound(k.begin()+i,k.end(),temp)-k.begin();
            if(index!=n)
            ans[it]=z[index].second;
            else
            ans[it]=-1;    
        }
        return ans;
    }
};
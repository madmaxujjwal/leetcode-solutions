class Solution {
public:
   static bool comp(pair<int,int> &a,pair<int,int> &b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first>b.first;
        
    }
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        vector<pair<int,int>> z;
        int n=profit.size();int m=worker.size();
        for(int i=0;i<n;i++){
            z.push_back({profit[i],difficulty[i]});
        }
        sort(z.begin(),z.end(),comp);
        sort(worker.begin(),worker.end(),greater<int>());
        int i=0;int c=0;
        int j=0;
        while(i<n&&j<m){
            if(z[i].second>worker[j]){
                i++;
            }
            else{
                c+=z[i].first;
                j++;
            }
        }
        return c;
    }
};
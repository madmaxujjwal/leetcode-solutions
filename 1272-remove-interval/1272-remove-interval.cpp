class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& toBeRemoved) {
        int n=intervals.size();
        int a=toBeRemoved[0];
        int b=toBeRemoved[1];
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            int s=intervals[i][0];
            int e=intervals[i][1];
            
            int r1=max(a,s);
            int r2=min(b,e);
            if(r1>r2)
            { ans.push_back({s,e});
                continue;}
            if(s<r1){
                ans.push_back({s,r1});
            }
            if(r2<e){
                ans.push_back({r2,e});
            }
        }
        return ans;
    }
};
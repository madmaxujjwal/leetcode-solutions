class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(points[i][1]>=points[i+1][0]){
                points[i+1][1]=min(points[i][1],points[i+1][1]);
                points[i][0]=-1;
                points[i][1]=-1;
            }
        }
        for(int i=0;i<n;i++){
            if(points[i][0]!=-1)
                ans++;
        }
        return ans;
    }
};
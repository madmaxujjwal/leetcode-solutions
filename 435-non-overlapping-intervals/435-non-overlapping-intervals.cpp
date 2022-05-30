class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        
        int c=0;
        for(int i=0;i<n-1;i++){
            if(intervals[i][1]>intervals[i+1][0]){
                if(intervals[i][1]>=intervals[i+1][1]){
                    c++;
                }
                else{
                    swap(intervals[i][1],intervals[i+1][1]);
                    c++;
                }
            }
            
        }
        return c;
        
    }
};
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n=intervals.size();
        if(n==0){
            return {newInterval};
        }
        int a=newInterval[0];
        int b=newInterval[1];
        int y=n;
        int x=-1;
        for(int i=0;i<n;i++){
            if(intervals[i][0]>b){
                y=i;
                break;
                
            }
        }
        for(int i=n-1;i>=0;i--){
            if(intervals[i][1]<a){
                x=i;
                break;
            }
        } vector<vector<int>> ans;
         
       
        if(x+1<n)
        a=min(a,intervals[x+1][0]);
        if(y-1>=0)
        b=max(b,intervals[y-1][1]);
       
       for(int i=0;i<=x;i++){
            ans.push_back({intervals[i][0],intervals[i][1]});
            
       }
       ans.push_back({a,b});
       for(int i=y;i<n;i++){
           ans.push_back({intervals[i][0],intervals[i][1]});
        }
        return ans;
    }
};
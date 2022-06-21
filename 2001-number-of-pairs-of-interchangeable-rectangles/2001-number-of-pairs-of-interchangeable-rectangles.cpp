class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        int n=rectangles.size();
        unordered_map<double,int> ht;
        long long int ans=0;
        for(int i=0;i<n;i++){
            double v=(double)rectangles[i][0]/(double)rectangles[i][1];
            ans+=ht[v];
            ht[v]++;
        }
        return ans;
    }
};
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        sort(points.begin(),points.end());
        vector<vector<int>> p;
        p.push_back(points[0]);
        for(int i=1;i<n;i++){
            vector<int> a=points[i];
            if(points[i]!=points[i-1]){
                p.push_back(a);
            }
        }
        unordered_map<double,double> ht;
        long double l=0;double z=0;
        for(int i=0;i<n;i++){
          
            for(int j=0;j<n;j++){
                if(i!=j){
                    double m;
                    if(p[i][0]-p[j][0]!=0)
                     m=((double)p[i][1]-(double)p[j][1])/((double)p[i][0]-(double)p[j][0]);
                    else
                      m=INT_MAX;
                     ht[m]++;
                    z=max(z,ht[m]);
                }
               
            }
           
            if(z>l){
                l=z;
            }
            ht.clear();
            z=0;
        }
        
        return l+1;
    }
};
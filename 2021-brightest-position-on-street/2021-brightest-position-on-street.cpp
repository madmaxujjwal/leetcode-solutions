class Solution {
public:
   static bool comp(pair<int,int> &a,pair<int,int> &b){
        if(a.first==b.first)
            return a.second<b.second;
        return a.first<b.first;
    }
    int brightestPosition(vector<vector<int>>& lights) {
       
        int n=lights.size();
       vector<pair<int,int>> z;
       
        for(int i=0;i<n;i++){
            int x=lights[i][0]-lights[i][1];
            int y=lights[i][0]+lights[i][1];
          z.push_back({x,0});
            z.push_back({y,1});
        }
        int maxi=INT_MIN;
        int pos=INT_MIN;
        int c=0;
        sort(z.begin(),z.end(),comp);
        for(int i=0;i<2*n;i++){
            if(z[i].second==0){
                c++;
            }
            else{
                c--;
            }
            if(maxi<c){
                maxi=c;
                pos=z[i].first;
            }
        }
        
        
        
        
        
       
        return pos;
        
        
    }
};
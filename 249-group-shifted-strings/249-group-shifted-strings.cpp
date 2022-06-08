class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int n=strings.size();
        vector<vector<string>> ans;
        vector<pair<vector<int>,string>> z;
        for(int i=0;i<n;i++){
            vector<int> k;
            if(strings[i].size()==1){
                k.push_back(-1);z.push_back({k,strings[i]});
                continue;
                
            }
            for(int j=0;j<strings[i].size()-1;j++){
                int ze=strings[i][j+1]-strings[i][j];
                if(ze<0){
                    ze+=26;
                }
                k.push_back(ze);
            }
            z.push_back({k,strings[i]});
            
            
        }
        sort(z.begin(),z.end());
        ans.push_back({z[0].second});
        for(int i=1;i<n;i++){
            if(z[i].first==z[i-1].first){
                ans[ans.size()-1].push_back(z[i].second);
            }
            else{
                ans.push_back({z[i].second});
            }
        }
        
       return ans;
        
    }
};
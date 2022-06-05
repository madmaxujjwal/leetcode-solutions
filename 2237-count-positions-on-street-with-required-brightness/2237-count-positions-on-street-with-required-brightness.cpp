class Solution {
public:
    int meetRequirement(int n, vector<vector<int>>& lights, vector<int>& requirement) {
        vector<int> range(n,0);
        for(int i=0;i<lights.size();i++){
            int a=max(0,lights[i][0]-lights[i][1]);
            int b=min(n-1,lights[i][0]+lights[i][1]);
            range[a]+=1;
            if(b<n-1){
                range[b+1]+=-1;
            }
            
        }
        for(int i=1;i<n;i++){
            range[i]+=range[i-1];
        }
        int c=0;
        for(int i=0;i<n;i++){
            if(requirement[i]<=range[i]){
                c++;
            }
        }
        return c;
    }
};
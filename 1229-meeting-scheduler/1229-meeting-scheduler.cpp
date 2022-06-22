class Solution {
public:
    vector<int> minAvailableDuration(vector<vector<int>>& slots1, vector<vector<int>>& slots2, int duration) {
        sort(slots1.begin(),slots1.end());
        sort(slots2.begin(),slots2.end());
        int n=slots1.size();
        int m=slots2.size();
        int i=0;
        int j=0;
        while((i<n)&&(j<m)){
            int s=max(slots1[i][0],slots2[j][0]);
            int e=min(slots1[i][1],slots2[j][1]);
            if((e-s)>=duration){
                return {s,s+duration};
            }
            if(slots2[j][1]<slots1[i][1]){
                j++;
            }
            else if(slots2[j][1]>slots1[i][1]){
                i++;
            }
            else{
                i++;j++;
            }
        }
        return {};
    }
    
};
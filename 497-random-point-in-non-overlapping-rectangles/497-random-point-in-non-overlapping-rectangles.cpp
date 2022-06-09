class Solution {
public:
    int n;
    vector<int> sum;
    vector<vector<int>> reacts;
    Solution(vector<vector<int>>& rects) {
         reacts=rects;
        n=rects.size();int area=0;
        for(int i=0;i<n;i++){
             area=area+abs((rects[i][2]-rects[i][0]+1)*(rects[i][3]-rects[i][1]+1));
            sum.push_back(area);
            
        }
    }
    
    vector<int> pick() {
        int p=sum[n-1]*((float)(rand())/RAND_MAX);
        int index=upper_bound(sum.begin(),sum.end(),p)-sum.begin();
        int x1=reacts[index][0];int x2=reacts[index][2];
        int y1=reacts[index][1];int y2=reacts[index][3];
        int a=rand()%(x2-x1+1)+x1;
        int b=rand()%(y2-y1+1)+y1;
        return {a,b};
        
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */
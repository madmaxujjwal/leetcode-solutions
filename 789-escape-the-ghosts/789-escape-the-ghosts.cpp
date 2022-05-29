class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        int mind=abs(target[0])+abs(target[1])+1;
        for(int i=0;i<ghosts.size();i++){
            int d=abs(target[0]-ghosts[i][0])+abs(target[1]-ghosts[i][1]);
            mind=min(mind,d);
        }
        
        if(mind<=(abs(target[0])+abs(target[1])))
            return false;
        
        return true;
    }
};
class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        int n=rooms[0].size();
        int inf=INT_MAX;
        queue<pair<pair<int,int>,int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==0){
                    q.push({{i,j},0});
                }
            }
        }
        
        while(q.size()>0){
            int x=q.front().first.first;
            int y=q.front().first.second;
            int l=q.front().second;
            q.pop();
            rooms[x][y]=l;
            if(x>0&&rooms[x-1][y]==inf){
                q.push({{x-1,y},l+1});
                rooms[x-1][y]=l+1;
            }
            if(y>0&&rooms[x][y-1]==inf){
                q.push({{x,y-1},l+1});
                rooms[x][y-1]=l+1;
            }
            if(x<m-1&&rooms[x+1][y]==inf){
                q.push({{x+1,y},l+1});
                rooms[x+1][y]=l+1;
            }
            if(y<n-1&&rooms[x][y+1]==inf){
                q.push({{x,y+1},l+1});
                rooms[x][y+1]=l+1;
            }
            
        }
       /* for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(rooms[i][j]==inf){
                    rooms[i][j]=-1;
                }
            }
        }
        */
    }
};
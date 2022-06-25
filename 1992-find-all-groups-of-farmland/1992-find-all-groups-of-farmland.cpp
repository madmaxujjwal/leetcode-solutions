class Solution {
public:
    int m;
    int n;
    vector<vector<int>> l;
    void dfs(int i,int j, vector<vector<bool>> &vis,int &c,int &d,int &ma){
        vis[i][j]=true;
        if(ma<(i+j)){
            c=i;
            d=j;
            ma=i+j;
            
        }
        if(i>=1&&vis[i-1][j]==false&&l[i-1][j]==1){
            dfs(i-1,j,vis,c,d,ma);
        }
        if(i<m-1&&vis[i+1][j]==false&&l[i+1][j]==1){
            dfs(i+1,j,vis,c,d,ma);
        }
        if(j>=1&&vis[i][j-1]==false&&l[i][j-1]==1){
            dfs(i,j-1,vis,c,d,ma);
        }
        if(j<n-1&&vis[i][j+1]==false&&l[i][j+1]==1){
            dfs(i,j+1,vis,c,d,ma);
        }
        
    }
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        m=land.size();
        n=land[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        vector<vector<int>> ans;
        l=land;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==false&&l[i][j]==1){
                    int a=i;
                    int b=j;
                    int c=i;
                    int d=j;
                    int ma=i+j;
                    dfs(i,j,vis,c,d,ma);
                    ans.push_back({a,b,c,d});
                }
            }
        }
        return ans;
    }
};
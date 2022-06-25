class Solution {
public:
    int m;
    int n;
    vector<vector<int>> g1;
    vector<vector<int>> g2;
    
    bool dfs(int i,int j,vector<vector<bool>> &v){
        v[i][j]=true;
        bool k=true;
        if(g1[i][j]==0)
            k=false;
        bool a1=true;  bool a2=true;  bool a3=true;  bool a4=true;
        if(i>=1&&v[i-1][j]==false&&g2[i-1][j]==1){
            a1=dfs(i-1,j,v);
        }
        if(i<m-1&&v[i+1][j]==false&&g2[i+1][j]==1){
            a2=dfs(i+1,j,v);
        }
        if(j>=1&&v[i][j-1]==false&&g2[i][j-1]==1){
            a3=dfs(i,j-1,v);
        }
        if(j<n-1&&v[i][j+1]==false&&g2[i][j+1]==1){
            a4=dfs(i,j+1,v);
        }
        return k&a1&a2&a3&a4;
    }
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
         m=grid2.size();
         n=grid2[0].size();
        g1=grid1;
        g2=grid2;
        int c=0;
        vector<vector<bool>> v(m,vector<bool>(n,false));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if((!v[i][j])&&g2[i][j]==1){
                    if(dfs(i,j,v))
                        c++;
                }
            }
        }
        return c;
    }
};
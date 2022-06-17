class Solution {
public:
    void search(int i,int j,int m,int n,vector<vector<int>>& grid,vector<vector<bool>> &vis,int v,int a,int &c){
        if(grid[i][j]==2){
            if(a==v){
                c++;
            
            }
            return ;
        }
        
        vis[i][j]=true;
        if((i-1)>=0&&vis[i-1][j]==false&&grid[i-1][j]!=-1){
            search(i-1,j,m,n,grid,vis,v,a+1,c);
        }
        if((i+1)<m&&vis[i+1][j]==false&&grid[i+1][j]!=-1){
            search(i+1,j,m,n,grid,vis,v,a+1,c);
        }
        if((j-1)>=0&&vis[i][j-1]==false&&grid[i][j-1]!=-1){
            search(i,j-1,m,n,grid,vis,v,a+1,c);
        }
        if((j+1)<n&&vis[i][j+1]==false&&grid[i][j+1]!=-1){
            search(i,j+1,m,n,grid,vis,v,a+1,c);
        }
        
        vis[i][j]=false;
    }
    
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<bool>> vis(m,vector<bool>(n,false));
        int v=2;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    v++;
                }
            }
        }
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    search(i,j,m,n,grid,vis,v,1,c);
                }
            }
        }
        return c;
    }
};
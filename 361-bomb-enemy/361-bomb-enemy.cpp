class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int h=grid.size();
        int w=grid[0].size();
        vector<vector<int>> dph(h,vector<int>(w,0));
        vector<vector<int>> dpv(h,vector<int>(w,0));
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(j==0){
                    if(grid[i][j]=='E')
                        dph[i][j]=1;
                    else
                        dph[i][j]=0;
                }
                else{
                    if(grid[i][j]=='W')
                        dph[i][j]=0;
                    else if(grid[i][j]=='0')
                        dph[i][j]=dph[i][j-1];
                    else
                        dph[i][j]=dph[i][j-1]+1;
                }
            }
        }
        for(int i=0;i<w;i++){
            for(int j=0;j<h;j++){
                if(j==0){
                    if(grid[j][i]=='E')
                        dpv[j][i]=1;
                    else
                        dpv[j][i]=0;
                }
                else{
                    if(grid[j][i]=='W')
                        dpv[j][i]=0;
                    else if(grid[j][i]=='0')
                        dpv[j][i]=dpv[j-1][i];
                    else
                        dpv[j][i]=dpv[j-1][i]+1;
                }
            }
        }
        
        for(int i=0;i<h;i++){bool v=true;int maxi=0;
            for(int j=w-1;j>=0;j--){
                if(grid[i][j]=='W'){
                    v=true;continue;maxi=0;
                }
                if(v){
                    if(grid[i][j]=='W')
                    {    v=true;
                     maxi=0;
                       
                    }
                    else {
                        maxi=dph[i][j];
                        v=false;
                    }
                }
                else{
                    dph[i][j]=maxi;
                }
            }
        }
        
         for(int i=0;i<w;i++){bool v=true;int maxi=0;
            for(int j=h-1;j>=0;j--){
                if(grid[j][i]=='W'){
                    v=true;continue;maxi=0;
                }
                if(v){
                    if(grid[j][i]=='W')
                    {    v=true;
                       
                    }
                    else {
                        maxi=dpv[j][i];
                        v=false;
                    }
                }
                else{
                    dpv[j][i]=maxi;
                }
            }
        }
        int maxi=0;
        for(int i=0;i<h;i++){
            for(int j=0;j<w;j++){
                if(grid[i][j]=='E'){
                    dph[i][j]=dph[i][j]+dpv[i][j]-1;
                }
                else if(grid[i][j]=='0'){
                     dph[i][j]=dph[i][j]+dpv[i][j];
                    maxi=max(maxi,dph[i][j]);
                }
                
                
            }
        }
        
        return maxi;
        
    }
};
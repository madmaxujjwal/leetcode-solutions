class Solution {
public:
    
    
    
    int longestLine(vector<vector<int>>& mat) {
        
    int m=mat.size();
    int n=mat[0].size();
    int vs[m][n];
    int hs[m][n];
    int d[m][n];
    int ad[m][n];
          int ans=0;
        
        if(mat[0][0]==1){
            vs[0][0]=1;
            hs[0][0]=1;
            d[0][0]=1;
            ad[0][0]=1;
            
        }
        else{
             vs[0][0]=0;
            hs[0][0]=0;
            d[0][0]=0;
            ad[0][0]=0;
        }
      
        for(int i=0;i<m;i++){
            
            for(int j=0;j<n;j++){
                
                
                if(i==0&&j==0){
                     ans=max({ans,vs[i][j],hs[i][j],d[i][j],ad[i][j]});
                    
                    continue;
                }
                if(mat[i][j]==1){
                    
                    
                    if(i>0)
                    vs[i][j]=vs[i-1][j]+1;
                    else
                    vs[i][j]=1;
                    if(j>0)
                    hs[i][j]=hs[i][j-1]+1;
                    else
                    hs[i][j]=1;
                    if(i>0&&j>0)
                    d[i][j]=d[i-1][j-1]+1;
                    else
                        d[i][j]=1;
                    if(j<n-1&&i>0)
                    ad[i][j]=ad[i-1][j+1]+1;
                    else
                        ad[i][j]=1;
                    
                }
                else
                {vs[i][j]=0;
            hs[i][j]=0;
            d[i][j]=0;
            ad[i][j]=0;
                
            }
            
                ans=max({ans,vs[i][j],hs[i][j],d[i][j],ad[i][j]});
            }
            
            
        }
        return ans;
    }
};
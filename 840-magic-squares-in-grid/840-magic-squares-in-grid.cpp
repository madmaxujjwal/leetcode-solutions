class Solution {
public:
    int m;
    int n;
    vector<vector<int>> g;
    bool cond(int i,int j){
        int r1=0;
        int r2=0;
        int r3=0;
        int c1=0;
        int c2=0;
        int c3=0;
        int d1=0;
        int d2=0;
        r1=g[i-1][j-1]+g[i-1][j]+g[i-1][j+1];
         r2=g[i][j-1]+g[i][j]+g[i][j+1];
         r3=g[i+1][j-1]+g[i+1][j]+g[i+1][j+1];
        c1=g[i-1][j-1]+g[i][j-1]+g[i+1][j-1];
       c2=g[i-1][j]+g[i][j]+g[i+1][j];
        c3=g[i-1][j+1]+g[i][j+1]+g[i+1][j+1];
        d1=g[i][j]+g[i-1][j-1]+g[i+1][j+1];
        d2=g[i][j]+g[i-1][j+1]+g[i+1][j-1];
        int a=g[i-1][j-1];
        int b=g[i-1][j];
        int c=g[i-1][j+1];
        int e=g[i][j-1];
        int f=g[i][j];
        int gi=g[i][j+1];
        int h=g[i+1][j-1];
        int ii=g[i+1][j];
        int jj=g[i+1][j+1];
        set<int> st;
        st.insert(a);
        st.insert(b);
        st.insert(c);
        st.insert(e);
        st.insert(f);
        st.insert(gi);
        st.insert(h);
        st.insert(ii);
        st.insert(jj);
        bool v=true;
        if(st.size()!=9||(st.find(0)!=st.end()))v=false;
        if((a<=9)&&b<=9&&c<=9&&e<=9&&f<=9&&gi<=9&&h<=9&&ii<=9&&jj<=9&&(c1==c2)&&(c2==c3)&&(c3==r1)&&(r1==r2)&&(r2==r3)&&(r3==d1)&&(d1==d2)&&(v==true))
            return true;
        return false;
        
        
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        
        g=grid;
        n=grid.size();
        m=grid[0].size();int c=0;
        
        for(int i=1;i<n-1;i++){
            
            for(int j=1;j<m-1;j++){
                
                
                if(cond(i,j))
                    c++;
                
            }
            
            
        }
        return c;
    }
};
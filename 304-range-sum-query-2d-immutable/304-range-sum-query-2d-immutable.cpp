class NumMatrix {
public:
    int n;
    int m;
    int sum[201][201];
    NumMatrix(vector<vector<int>>& matrix) {
        n=matrix.size();
        m=matrix[0].size();
       for(int i=0;i<=m;i++){
           sum[i][0]=0;
       }
        for(int i=0;i<=n;i++){
           sum[0][i]=0;
       }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                int v=matrix[i-1][j-1];
                int a=0;int b=0;
                
                    a=sum[i][j-1];
                
                
                    b=sum[i-1][j]-sum[i-1][j-1];
                
                sum[i][j]=v+a+b;
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
       // return sum[2][3];
        return sum[row2+1][col2+1]-sum[row2+1][col1]-sum[row1][col2+1]+sum[row1][col1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
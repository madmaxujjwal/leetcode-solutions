class Solution {
public:
     void search(int i,int n,vector<int> &column,vector<int> &diag1,vector<int> &diag2,int &c){
        if(i==n){
            c++;
            return ;
        }
        for(int j=0;j<n;j++){
            if(column[j]==1||diag1[j+i]==1||diag2[i-j+n-1]==1){
                continue;
            }
            column[j]=1;diag1[j+i]=1;diag2[i-j+n-1]=1;
            search(i+1,n,column,diag1,diag2,c);
            column[j]=0;diag1[j+i]=0;diag2[i-j+n-1]=0;
            
        }
        
    }
    int totalNQueens(int n) {
         vector<int> column(n,0);
        vector<int> diag1(2*n-1,0);
        vector<int> diag2(2*n-1,0);
        int c=0;
        search(0,n,column,diag1,diag2,c);
        return c;
    }
};
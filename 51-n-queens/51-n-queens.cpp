class Solution {
public:
    void search(int i,vector<vector<string>> &ans,vector<string> &board,  vector<int> &column,  vector<int> &diag1,  vector<int> &diag2,int n){
        if(i==n){
            ans.push_back(board);
            return;
        }
        for(int j=0;j<n;j++){
            if(column[j]==1||diag1[j+i]==1||diag2[i-j+n-1]==1){
                continue;
            }
            column[j]=1;diag1[j+i]=1;diag2[i-j+n-1]=1;
            board[i][j]='Q';
            search(i+1,ans,board,column,diag1,diag2,n);
            column[j]=0;diag1[j+i]=0;diag2[i-j+n-1]=0;
            board[i][j]='.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string z="";
        for(int i=0;i<n;i++)
        {
            z=z+'.';
        }
        vector<string> board(n,z);
        vector<int> column(n,0);
        vector<int> diag1(2*n-1,0);
        vector<int> diag2(2*n-1,0);
        search(0,ans,board,column,diag1,diag2,n);
        return ans;
        
        
        
        
        
    }
};
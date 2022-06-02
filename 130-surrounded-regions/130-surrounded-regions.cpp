class Solution {
public:
    void dfs1(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited1,int n,int m){
        visited1[i][j]=true;
        board[i][j]='X';
        if((i-1)>=0&&visited1[i-1][j]!=true&&board[i-1][j]=='O'){
            dfs1(i-1,j,board,visited1,n,m);
        }
        if((i+1)<n&&visited1[i+1][j]!=true&&board[i+1][j]=='O'){
             dfs1(i+1,j,board,visited1,n,m);
        }
        if((j-1)>=0&&visited1[i][j-1]!=true&&board[i][j-1]=='O'){
             dfs1(i,j-1,board,visited1,n,m);
        }
        if((j+1)<m&&visited1[i][j+1]!=true&&board[i][j+1]=='O'){
             dfs1(i,j+1,board,visited1,n,m);
        }
    }
     bool dfs2(int i,int j,vector<vector<char>>& board,vector<vector<bool>>& visited2,int n,int m){
        visited2[i][j]=true;bool cur=true;
        if(i==0||i==n-1||j==0||j==m-1){
            cur= false;
        }
         bool a,b,c,d;
        if((i-1)>=0&&visited2[i-1][j]!=true&&board[i-1][j]=='O'){
           a= dfs2(i-1,j,board,visited2,n,m);
            cur=cur&a;
        }
        if((i+1)<n&&visited2[i+1][j]!=true&&board[i+1][j]=='O'){
            b= dfs2(i+1,j,board,visited2,n,m);cur=cur&b;
        }
        if((j-1)>=0&&visited2[i][j-1]!=true&&board[i][j-1]=='O'){
            c= dfs2(i,j-1,board,visited2,n,m);cur=cur&c;
        }
        if((j+1)<m&&visited2[i][j+1]!=true&&board[i][j+1]=='O'){
            d= dfs2(i,j+1,board,visited2,n,m);cur=cur&d;
        }
         return cur;
    }
    
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>> visited1(n,vector<bool>(m,false));
        vector<vector<bool>> visited2(n,vector<bool>(m,false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(visited1[i][j]==true||board[i][j]=='X')
                    continue;
                if(dfs2(i,j,board,visited1,n,m)){
                    dfs1(i,j,board,visited2,n,m);
                }
            }
        }
        
    }
};
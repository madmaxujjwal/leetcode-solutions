class Solution {
public:
    
   bool search(vector<vector<char>>& board,string word,int in,int px,int py,int m,int n,int i,int j,int l,vector<vector<bool>> &visited){
       visited[i][j]=true;
        if(in==l){
            return true;
        }
        bool v=false;
        if((i-1>=0)&&((i-1)!=px||(j!=py))&&(board[i-1][j]==word[in])&&visited[i-1][j]==false){
           v=v| search(board,word,in+1,i,j,m,n,i-1,j,l,visited);
        }
         if((i+1<m)&&((i+1)!=px||(j!=py))&&(board[i+1][j]==word[in])&&visited[i+1][j]==false){
           v=v| search(board,word,in+1,i,j,m,n,i+1,j,l,visited);
        }
         if((j-1>=0)&&((i)!=px||((j-1)!=py))&&(board[i][j-1]==word[in])&&visited[i][j-1]==false){
           v=v| search(board,word,in+1,i,j,m,n,i,j-1,l,visited);
        }
         if((j+1<n)&&((i)!=px||((j+1)!=py))&&(board[i][j+1]==word[in])&&visited[i][j+1]==false){
            v=v|search(board,word,in+1,i,j,m,n,i,j+1,l,visited);
        }
       visited[i][j]=false;
    return v;
    }
    bool exist(vector<vector<char>>& board, string word) {
        //if(word=="aaaaaaaaaaaaa")return false;
        int m=board.size();
        int n=board[0].size();
        int l=word.size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
    //    if(l>2*m+2*n-4&&(m!=1&&n!=1))
        //    return false;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    bool z=search(board,word,1,-1,-1,m,n,i,j,l,visited);
                    if(z)
                        return true;
                }
            }
        }
        return false;
    }
};
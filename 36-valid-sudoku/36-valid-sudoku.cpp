class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            unordered_map<char,int> ht;
            for(int j=0;j<9;j++){
                if(board[i][j]=='.')
                    continue;
                if(ht.find(board[i][j])!=ht.end())
                    return false;
                ht[board[i][j]]++;
            }
        }
        for(int i=0;i<9;i++){
            unordered_map<char,int> ht;
            for(int j=0;j<9;j++){
                 if(board[j][i]=='.')
                    continue;
                if(ht.find(board[j][i])!=ht.end())
                    return false;
                ht[board[j][i]]++;
            }
        }
        for(int k=0;k<9;k++){
            unordered_map<char,int> ht;
            int a=(k/3)*3;
            for(int i=a;i<a+3;i++){
                int b=(k%3)*3;
                for(int j=b;j<b+3;j++){
                     if(board[i][j]=='.')
                    continue;
                    if(ht.find(board[i][j])!=ht.end())
                    return false;
                ht[board[i][j]]++;
                }
            }
        }
        return true;
    }
};
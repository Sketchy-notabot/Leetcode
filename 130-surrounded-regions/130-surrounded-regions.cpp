class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j){
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return;
        if(board[i][j]!='O')
            return;
        board[i][j]='A';
        dfs(board,i+1,j);
        dfs(board,i,j+1);
        dfs(board,i-1,j);
        dfs(board,i,j-1);
    }
    void solve(vector<vector<char>>& board) {
        for(int i=0;i<board[0].size();i++){
            if(board[0][i]=='O')
                dfs(board,0,i);
            if(board[board.size()-1][i]=='O')
                dfs(board,board.size()-1,i);
        }
        for(int j=1;j<board.size()-1;j++){
            if(board[j][0]=='O')
                dfs(board,j,0);
            if(board[j][board[0].size()-1]=='O')
                dfs(board,j,board[0].size()-1);
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='O')
                    board[i][j]='X';
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='A')
                    board[i][j]='O';
            }
        }
    }
};
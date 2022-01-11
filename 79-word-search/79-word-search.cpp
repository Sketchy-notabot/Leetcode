class Solution {
public:
    
    bool dfs(vector<vector<char>>& board, string word, int k, int i, int j, vector<vector<bool>>& vis){
        if(i<0||j<0||i>=board.size()||j>=board[0].size())
            return false;
        if(vis[i][j])
            return false;
        if(board[i][j]!=word[k])
            return false;
        if(k+1==word.size())
            return true;      
        vis[i][j]=1;
        if(dfs(board,word,k+1,i+1,j, vis)||dfs(board,word,k+1,i-1,j, vis)||
                                     dfs(board,word,k+1,i,j+1, vis)||dfs(board,word,k+1,i,j-1, vis)){
            return true;
        }
        vis[i][j]=0;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), std::vector<bool>(board[0].size(), 0));
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                vector<vector<bool>> vis(board.size(), std::vector<bool>(board[0].size(), 0));
                if(dfs(board,word,0,i,j, vis))
                    return true;
            }
        }
        return false;
    }
};
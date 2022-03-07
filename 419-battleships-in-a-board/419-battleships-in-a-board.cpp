class Solution {
public:
    int countBattleships(vector<vector<char>>& board) {
        int ans = 0;
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]=='X'){
                    ans++;
                    int temp = i+1;
                    if(temp!=board.size()){
                        while(board[temp][j]=='X') {
                            board[temp][j] = '.';
                            temp++;
                            if(temp==board.size())    break;
                        }
                    }
                    temp = j+1;
                    if(temp!=board[0].size()){
                        while(board[i][temp]=='X') {
                            board[i][temp] = '.';
                            temp++;
                            if(temp==board[0].size())    break;
                        }
                    }
                }
            }
        }
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        return ans;
    }
};
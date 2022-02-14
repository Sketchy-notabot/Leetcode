class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0, close = 0, moves = 0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                open++;
            }
            else{
                if(open==0)
                    moves++;
                else
                    open--;
            }
        }
        moves+=open;
        return moves;
    }
};
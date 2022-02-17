class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        vector<int> ans(s.length(), 0);
        for(int i=0;i<s.length();i++){
            int currRow = startPos[0];
            int currCol = startPos[1];
            for(int j=i;j<s.length();j++){
                if(s[j]=='R') currCol++;
                if(s[j]=='L') currCol--;
                if(s[j]=='D') currRow++;
                if(s[j]=='U') currRow--;
                if(currCol>=0&&currCol<n&&currRow>=0&&currRow<n)
                    ans[i]++;
                else
                    break;
            }
        }
        return ans;
    }
};
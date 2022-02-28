class Solution {
public:
    // int countUtil(int n, vector<int> s){
    //     if(s.size()==n)
    //         return 1;
    //     int ans = 0;
    //     int j = s.size()>0?s[s.size()-1]:0;
    //     for(;j<5;j++){
    //         s.push_back(j);
    //         ans += countUtil(n, s);
    //         s.pop_back();
    //     }
    //     return ans;
    // }
    int countVowelStrings(int n) {
        vector<vector<int>> dp(n+1);
        for(int i=0;i<=n;i++){
            dp[i] = vector<int>(5);
            for(int j=0;j<5;j++){
                if(i==0||j==0){
                    dp[i][j]=1;
                    continue;
                }
                dp[i][j] = dp[i-1][j] + dp[i][j-1];
            }
        }
        return dp[n][4];
    }
};
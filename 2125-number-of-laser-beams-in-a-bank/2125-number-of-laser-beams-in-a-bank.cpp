class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans = 0, prev = -1;
        for(string row : bank){
            int lasers=0;
            for(int i=0;i<row.length();i++){
                lasers += row[i]-'0';
            }
            if(lasers==0)
                continue;
            if(prev!=-1)
                ans += prev*lasers;
            prev = lasers;
        }
        return ans;
    }
};
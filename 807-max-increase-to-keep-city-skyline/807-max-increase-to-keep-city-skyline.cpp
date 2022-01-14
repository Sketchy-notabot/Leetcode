class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        vector<int> rowmax(grid.size());
        vector<int> colmax(grid.size());
        int ans = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                rowmax[i] = max(rowmax[i], grid[i][j]);
                colmax[j] = max(colmax[j], grid[i][j]);
            }
        }
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                ans += min(rowmax[i], colmax[j]) - grid[i][j]; 
            }
        }
        return ans;
    }
};
class Solution {
public:
    int connectedComponents(vector<vector<char>>& grid, int i, int j){
        if(i<0||j<0||i>=grid.size()||j>=grid[i].size()||grid[i][j]!='1')
            return 0;
        grid[i][j]=2;
        int ans = 0;
        ans += connectedComponents(grid, i+1, j);
        ans += connectedComponents(grid, i, j-1);
        ans += connectedComponents(grid, i-1, j);
        ans += connectedComponents(grid, i, j+1);
        return 1;
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]=='1'){
                    islands += connectedComponents(grid, i, j);
                }
            }
        }
        return islands;
    }
};
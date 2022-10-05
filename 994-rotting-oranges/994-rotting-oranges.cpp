class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j]==2)
                    q.push({i,j});
                if(grid[i][j]==1)
                    fresh++;
            }
        }
        int dir[] = {-1, 0, 1, 0, -1};
        int time = -1;
        while(!q.empty()){
            int n = q.size();
            for(int i=0;i<n;i++){
                pair<int, int> curr = q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int newX = curr.first + dir[i];
                    int newY = curr.second + dir[i+1];
                    if(newX<0||newY<0||newX>=grid.size()||newY>=grid[0].size()||grid[newX][newY]!=1)
                        continue;
                    q.push({newX, newY});
                    grid[newX][newY]=2;
                    fresh--;
                }
            }
            time++;
        }
        if(fresh) return -1;
        return time==-1?0:time;
    }
};
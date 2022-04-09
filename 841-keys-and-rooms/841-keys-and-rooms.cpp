class Solution {
public:
    void util(vector<vector<int>> rooms, vector<bool>& visited, int room){
        visited[room]=true;
        for(int i=0;i<rooms[room].size();i++){
            if(!visited[rooms[room][i]])
                util(rooms, visited, rooms[room][i]);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<bool> visited(rooms.size(), false);
        util(rooms, visited, 0);
        for(bool temp : visited){
            if(!temp)
                return false;
        }
        return true;
    }
};
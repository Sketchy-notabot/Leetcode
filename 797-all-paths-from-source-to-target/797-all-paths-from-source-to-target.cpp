class Solution {
public:
    void dfsUtil(int curr, int n, vector<int>& path, vector<vector<int>>& paths, vector<vector<int>>& graph){
        path.push_back(curr);
        if(curr==n-1){
            paths.push_back(path);
        }
        else{
            for(int next : graph[curr]){
                dfsUtil(next, n, path, paths, graph);
            }
        }
        path.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> paths;
        vector<int> path;
        dfsUtil(0, graph.size(), path, paths, graph);
        return paths;
    }
};
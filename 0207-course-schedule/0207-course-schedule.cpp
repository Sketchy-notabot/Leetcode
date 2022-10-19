class Solution{ 
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> visited(numCourses, false);
        vector<int> inEdges(numCourses, 0);
        vector<vector<int>> adj(numCourses);
        for(vector<int> pre: prerequisites){
            adj[pre[1]].push_back(pre[0]);
            inEdges[pre[0]]++;
        }
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(inEdges[i]==0)
                q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            visited[curr]=true;
            for(int next : adj[curr]){
                if(visited[next])
                    continue;
                inEdges[next]--;
                if(inEdges[next]==0)
                    q.push(next);
            }
        }
        for(int i=0;i<numCourses;i++){
            if(!visited[i])
                return false;
        }
        return true;
    }
};
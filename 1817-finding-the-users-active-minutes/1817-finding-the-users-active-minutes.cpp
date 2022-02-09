class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        map<int, set<int>> m;
        for(int i=0;i<logs.size();i++){
            m[logs[i][0]].insert(logs[i][1]);
        }
        vector<int> answer(k, 0);
        for(auto it=m.begin();it!=m.end();it++){
            answer[it->second.size()-1]++;
        }
        return answer;
    }
};
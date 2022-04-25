class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;
        for(vector<int> match : matches){
            if(mp.find(match[0])==mp.end())
                mp[match[0]] = 0;
            mp[match[1]]++;
        }
        vector<vector<int>> ans;
        vector<int> temp1, temp2;
        for(auto it=mp.begin();it!=mp.end();it++){
            if(it->second==0)
                temp1.push_back(it->first);
            if(it->second==1)
                temp2.push_back(it->first);
        }
        ans.push_back(temp1);
        ans.push_back(temp2);
        return ans;
    }
};
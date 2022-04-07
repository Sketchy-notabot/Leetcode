class Solution {
public:
    int numSplits(string s) {
        map<char, pair<int, int>> mp;
        for(int i=0;i<s.length();i++){
            if(mp.find(s[i])==mp.end())
                mp[s[i]] = {i, i};
            else
                mp[s[i]].second = i;
        }
        // for(auto it=mp.begin();it!=mp.end();it++)
        //     cout<<it->first<<" "<<it->second.first<<" "<<it->second.second<<endl;
        set<char> se;
        int left = 0, right = mp.size(), ans=0;
        for(int i=0;i<s.length();i++){
            if(se.size()==right)
                ans++;
            se.insert(s[i]);
            if(mp[s[i]].second==i)
                right--;
        }
        return ans;
    }
};
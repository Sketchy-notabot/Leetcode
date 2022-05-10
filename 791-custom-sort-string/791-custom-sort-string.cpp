class Solution {
public:
    string customSortString(string order, string s) {
        map <char, int> mp;
        int i;
        for(i=0;i<order.size();i++)
            mp[order[i]]=i;
        for(int j=0;j<s.size();j++){
            if(mp.find(s[j])==mp.end())
                mp[s[j]]=++i;
        }
        sort(s.begin(), s.end(), 
            [&mp](const char & a, const char & b) -> bool{ 
                return mp[a] < mp[b]; 
            });
        return s;
    }
};
class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        
        vector<string> ans;
        for(int i=0;i<words.size();i++){
            map<char, char> mp;
            set<char> s;
            int j;
            for(j=0;j<pattern.size();j++){
                if(mp.find(pattern[j])==mp.end()&&s.find(words[i][j])==s.end()){
                    mp[pattern[j]] = words[i][j];
                    s.insert(words[i][j]);
                }
                else{
                    if(mp[pattern[j]]!=words[i][j])
                        break;
                }
            }
            if(j==pattern.size())
                ans.push_back(words[i]);
        }
        return ans;
    }
};
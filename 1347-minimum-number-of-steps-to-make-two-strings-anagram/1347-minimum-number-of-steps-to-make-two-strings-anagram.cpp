class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> sm, tm;
        for(int i=0;i<s.length();i++){
            if(sm.find(s[i])==sm.end())
                sm[s[i]]=1;
            else
                sm[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            if(tm.find(t[i])==tm.end())
                tm[t[i]]=1;
            else
                tm[t[i]]++;
        }
        map<char, int>::iterator it;
        int minSteps = 0;
        for(it=sm.begin();it!=sm.end();it++){
            if(tm.find(it->first)==tm.end()){
                minSteps += it->second;
                // cout<<it->first<<it->second;
            }
            else
                minSteps += max(it->second - tm[it->first], 0);
            // cout<<" "<<minSteps<<" ";
        }
        return minSteps;
    }
};
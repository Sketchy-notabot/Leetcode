class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.length()==0)
            return 0;
        vector<int> prevOcc(256, -1);
        int res = 0, start=-1;
        for(int i=0;i<s.length();i++){
            if(prevOcc[s[i]]>start)
                start = prevOcc[s[i]];
            prevOcc[s[i]]=i;
            res = max(res, i-start);
        }
        return res==-1?s.length():res;
    }
};
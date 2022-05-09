class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        bool f1=false, f2=false;
        for(int i=0;i<s1.length();i++){
            if(s1[i]>s2[i])
                f1=true;
            else if(s1[i]<s2[i])
                f2=true;
            if(f1&&f2)
                return false;
        }
        return true;
    }
};
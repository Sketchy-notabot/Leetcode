class Solution {
public:
    int minFlips(string target) {
        string temp = "";
        temp+=target[0];
        for(int i=1;i<target.length();i++){
            if(target[i]!=target[i-1])
                temp+=target[i];
        }
        if(temp.length()==1&&temp=="0")
            return 0;
        if(temp[0]=='0')
            return temp.length()-1;
        return temp.length();
    }
};
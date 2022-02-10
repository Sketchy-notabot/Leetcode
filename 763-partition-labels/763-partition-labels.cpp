class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, pair<int, int>> firstlast;
        for(int i=0;i<s.length();i++){
            if(firstlast.find(s[i])==firstlast.end())
                firstlast[s[i]] = {i, i};
            else
                firstlast[s[i]].second = i;
        }
        vector<int> ans;
        int start = 0, end = -1;
        while(start<s.length()){
            int i = start;
            end = firstlast[s[i]].second;
            while(i<end){
                i++;
                if(end<firstlast[s[i]].second)
                    end = firstlast[s[i]].second;
            }
            ans.push_back(end-start+1);
            start = end + 1;
        }
        return ans;
    }
};
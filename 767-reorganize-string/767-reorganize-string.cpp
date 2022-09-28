class Solution {
public:
    string reorganizeString(string s) {
        priority_queue<pair<int, char>> pq;
        vector<int> freq(26, 0);
        for(char c: s){
            freq[c-'a']++;
        }
        string res="";
        int max_ele = 0;
        for(int i=0;i<26;i++){
            if(freq[i]==0)
                continue;
            pq.push({freq[i],'a'+i});
            max_ele = max(max_ele, freq[i]);
        }
        if(max_ele>(s.length()+1)/2)
            return "";
        while(!pq.empty()){
            pair<int, char> curr = pq.top();
            pq.pop();
            if(res=="")
                res+=curr.second;
            else if(res[res.length()-1]!=curr.second)
                res+=curr.second;
            else if(res[res.length()-1]==curr.second){
                pair<int, char> temp = pq.top();
                pq.pop();
                res+=temp.second;
                temp.first--;
                if(temp.first)
                    pq.push(temp);
                curr.first++;
            }
            curr.first--;
            if(curr.first)
                pq.push(curr);
        }
        return res;
    }
};
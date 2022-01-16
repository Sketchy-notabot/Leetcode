class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> m;
        for(int i=0;i<groupSizes.size();i++){
            if(m.find(groupSizes[i])!=m.end()){
                m[groupSizes[i]].push_back(i);
            }
            else{
               m[groupSizes[i]] = vector<int>(1, i); 
            }
        }
        vector<vector<int>> ans;
        for(auto it=m.begin();it!=m.end();it++){
            vector<int> temp(it->first);
            for(int i=0;i<it->second.size();i++){
                if(i%it->first==0){
                    if(i!=0)
                        ans.push_back(temp);
                    temp = {it->second[i]};
                }
                else{
                    temp.push_back(it->second[i]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
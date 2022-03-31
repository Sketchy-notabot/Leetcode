class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        vector<vector<int>> ans;
        int i=0,j=0;
        while(i<firstList.size()&&j<secondList.size()){
            if(firstList[i][1]>secondList[j][1]){
                int temp = secondList[j][1] - max(firstList[i][0], secondList[j][0]);
                if(temp>-1)
                    ans.push_back({max(firstList[i][0], secondList[j][0]), secondList[j][1]});
                j++;
            }
            else{
                int temp = firstList[i][1] - max(firstList[i][0], secondList[j][0]);
                if(temp>-1)
                    ans.push_back({max(firstList[i][0], secondList[j][0]), firstList[i][1]});
                i++;
            }
        }
        return ans;
    }
};
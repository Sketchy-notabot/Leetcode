class Solution {
public:

    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        set<int> s;
        for(int i=0;i<points.size();i++){
            s.insert(points[i][0]);
        }
        int prev = -1, maxArea=0;
        for (int x : s){
            if(prev!=-1)
                maxArea = max(maxArea, x - prev);
            prev = x;
        }   
        return maxArea;
    }
};
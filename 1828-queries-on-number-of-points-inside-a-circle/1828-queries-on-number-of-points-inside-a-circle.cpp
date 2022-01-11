class Solution {
public:
    static bool compare(vector<int> a, vector<int> b){
        if(a[0]<b[0])
            return true;
        else if(a[0]==b[0])
            return a[1]<b[1];
        else
            return false;
    }

    int find_left_boundry_index(vector<vector<int> > & points , int x_center , int y_center , int r) {

    int lo = 0, hi = points.size();

    while (lo < hi) {
        int mi = lo + (hi - lo ) / 2;
        if (x_center - r <= points[mi][0])
            hi = mi;
        else
            lo = mi + 1;
    }
    return hi == points.size() or (points[hi][0] > x_center + r or points[hi][0] < x_center - r) ? points.size() : hi;

    }
    int square(int x){
        return x*x;
    }
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {

        sort(points.begin(), points.end(), compare);
        vector<int> ans;

        for (int i = 0; i < queries.size(); i++) {
            int x_c = queries[i][0], y_c = queries[i][1], r = queries[i][2];
            int index = find_left_boundry_index(points, x_c , y_c, r); 
            int count = 0;

            for (int j = index; j < points.size() and points[j][0] <= x_c + r; j++) {

                int x = points[j][0];
                int y = points[j][1];
                count += square(x_c - x) + square(y_c - y) <= r * r;
            }

            ans.push_back(count);
        }
        return ans;
    }
};
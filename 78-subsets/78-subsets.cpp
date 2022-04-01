class Solution {
public:
    
    void util(vector<int> nums, vector<vector<int>>& ans, vector<int> temp, int start){
        ans.push_back(temp);
        for(int i=start;i<nums.size();i++){
            temp.push_back(nums[i]);
            util(nums, ans, temp, i+1);
            temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        util(nums, ans, {}, 0);
        return ans;
    }
};
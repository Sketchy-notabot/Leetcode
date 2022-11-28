class Solution {
public:
    void util(vector<vector<int>>& ans, vector<int> temp, vector<int> nums, int target, int start){
        if(target==0){
            ans.push_back(temp);
            return;
        }
        for(int i=start;i<nums.size();i++){
            if(nums[i]<=target){
                temp.push_back(nums[i]);
                util(ans, temp, nums, target-nums[i], i);
                temp.pop_back();
            }
        }  
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        util(ans, temp, candidates, target, 0);
        return ans;
    }
};
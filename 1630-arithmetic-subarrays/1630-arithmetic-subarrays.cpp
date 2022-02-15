class Solution {
public:
    
    bool checkArithmetic(vector<int> nums){
        sort(nums.begin(), nums.end());
        int diff = nums[1]-nums[0];
        for(int i=2;i<nums.size();i++){
            if(nums[i]-nums[i-1]!=diff)
                return false;
        }
        return true;
    }
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        vector<bool> ans(l.size(), false);
        for(int i=0;i<l.size();i++){
            vector<int> nums_query = {nums.begin() + l[i], nums.begin() + r[i] + 1};
            if(checkArithmetic(nums_query))
                ans[i]=true;
        }
        return ans;
    }
};
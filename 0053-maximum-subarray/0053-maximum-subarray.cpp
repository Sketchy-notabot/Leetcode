class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int globalSum = INT_MIN, currMax=0;
        for(int i=0;i<nums.size();i++){
            currMax = max(currMax + nums[i], nums[i]);
            globalSum = max(globalSum, currMax);
        }
        return globalSum;
    }
};
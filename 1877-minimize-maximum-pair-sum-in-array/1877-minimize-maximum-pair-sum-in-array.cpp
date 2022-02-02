class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int maxPair = -1;
        int n = nums.size();
        for(int i=0;i<n/2;i++){
            maxPair = max(maxPair, nums[i]+nums[n-1-i]);
        }
        return maxPair;
    }
};
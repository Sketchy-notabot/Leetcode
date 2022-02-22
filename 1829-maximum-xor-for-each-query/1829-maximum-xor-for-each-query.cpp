class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int xor_value = nums[0];
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            if(i!=0)
                xor_value = xor_value^nums[i];
            ans[nums.size()-1-i] = pow(2, maximumBit) - 1 - xor_value;            
        }
        return ans;
    }
};
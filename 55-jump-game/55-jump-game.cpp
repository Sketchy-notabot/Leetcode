class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==1)
            return true;
        if(nums[0]==0)
            return false;
        int jump=1;
        for(int i=0;i<nums.size();i++){
            if(jump==0)
                return false;
            jump=(jump-1>nums[i])?jump-1:nums[i];
        }
        return true;
    }
};
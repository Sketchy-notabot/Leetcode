class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> lProd(nums.size(), 1);
        vector<int> rProd(nums.size(), 1);
        lProd[0]=1;
        rProd[nums.size()-1]=1;
        for(int i=1;i<nums.size();i++){
            lProd[i]=lProd[i-1]*nums[i-1];
            rProd[nums.size()-i-1]=rProd[nums.size()-i]*nums[nums.size()-i];
        }
        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            ans[i]=lProd[i]*rProd[i];
        }
        return ans;
    }
};
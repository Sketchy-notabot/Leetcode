class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()<=1)  return nums.size();
        vector<int> res(nums.size(),1);
        res[0]=1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j])
                    res[i]=max(res[i],res[j]+1);
            }
            cout<<res[i]<<" ";
        }
        return *max_element(res.begin(), res.end());
    }
};
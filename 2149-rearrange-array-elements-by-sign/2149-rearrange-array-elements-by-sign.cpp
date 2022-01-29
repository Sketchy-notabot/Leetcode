class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> res(nums.size());
		// two positions
        int pos = 0,neg = 1;
        for(int &num : nums){
			// iterate over the array and update the result
            if(num > 0) res[pos] = num, pos += 2;
            else res[neg] = num, neg += 2;
        }
        return res;           
    }
};
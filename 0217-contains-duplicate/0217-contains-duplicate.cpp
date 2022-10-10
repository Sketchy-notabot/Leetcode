class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(int num: nums){
            if(s.count(num)>0)
                return true;
            s.insert(num);
        }
        return false;
    }
};
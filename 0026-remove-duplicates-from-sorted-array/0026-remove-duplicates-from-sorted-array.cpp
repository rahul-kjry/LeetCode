class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int> res;
        res.push_back(nums[0]);
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] != nums[i - 1]) {
                res.push_back(nums[i]);
            }
        }
        nums = res;
        return nums.size();
    }
};
class Solution {
public:
    int maxScore(vector<int>& nums, int k) {
        int len = nums.size();
        int wLen = len - k;
        int res = INT_MIN;
        int tSum = accumulate(nums.begin(), nums.end(), 0);
        int cSum = accumulate(nums.begin(), nums.begin() + wLen, 0);
        for (int i = len - k; i < len; ++i) {
            res = max(res, tSum - cSum);
            cSum += nums[i] - nums[i - wLen];
        }
        res = max(res, tSum - cSum);
        return res;
    }
};
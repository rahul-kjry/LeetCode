class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int len = nums.size();
        vector<int> pre(len), pst(len), res(len);
        partial_sum(nums.begin(), nums.end(), pre.begin(), multiplies<int>());
        partial_sum(nums.rbegin(), nums.rend(), pst.rbegin(), multiplies<int>());
        for (int i = 1; i < len - 1; ++i) {
            res[i] =  pre[i - 1] * pst[i + 1];
        }
        res[0] = pst[1];
        res[len - 1] = pre[len - 2];
        return res;
    }
};
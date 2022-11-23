class Solution {
public:
    #define fi first
    #define se second
    int waysToMakeFair(vector<int>& nums) {
        int len = nums.size();
        vector<pair<int, int>> pre(len + 1), pst(len + 1);
        int od = 0, ev = 0;
        for (int i = 0; i < len; ++i) {
            if (i & 1) {
                od += nums[i];
            }
            else {
                ev += nums[i];
            }
            pre[i + 1] = {od, ev};
        }
        od = 0, ev = 0;
        for (int i = len - 1; i >= 0; --i) {
            if (i & 1) {
                od += nums[i];
            }
            else {
                ev += nums[i];
            }
            pst[i] = {od, ev};
        }
        int res = 0;
        for (int i = 0; i < len; ++i) {
            if (pre[i].fi + pst[i + 1].se == pre[i].se + pst[i + 1].fi) {
                res += 1;
            }
        }
        return res;
    }
};
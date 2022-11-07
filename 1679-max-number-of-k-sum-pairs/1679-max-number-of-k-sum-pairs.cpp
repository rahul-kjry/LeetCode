class Solution {
public:
    int maxOperations(vector<int>& nums, int p) {
        map<int, int> mp;
        for (int & i : nums) {
            ++ mp[i];
        }
        int res = 0;
        for (auto & [k, v] : mp) {
            if (k) {
                if (k == p - k) {
                    res += mp[k] / 2;
                }
                else {
                    res += min(mp[k], mp[p - k]);
                }
                mp[k] = 0;
                mp[p - k] = 0;
            }
        }
        return res;
    }
};
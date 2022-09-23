class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int sum = 0, res = 0;
        for (int & i : nums) {
            sum += i;
            res += mp[sum - k];
            ++ mp[sum];
        }
        return res;
    }
};
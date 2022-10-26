class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int sum = 0, pre = 0;
        unordered_set<int> set;
        for (int & i : nums) {
            sum += i;
            if (set.find(sum % k) != set.end()) {
                return true;
            }
            set.insert(pre);
            pre = sum % k;
        }
        return false;
    }
};
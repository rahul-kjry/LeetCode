class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int, int> map;
        for (int & i : nums) ++ map[i];
        vector<int> res;
        for (int i = 1; i <= nums.size(); ++i) {
            if (map[i] == 2) {
                res.push_back(i);
            }
        }
        for (int i = 1; i <= nums.size(); ++i) {
            if (map[i] == 0) {
                res.push_back(i);
            }
        }
        return res;
    }
};
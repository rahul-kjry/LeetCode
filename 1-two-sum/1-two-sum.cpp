class Solution {
public:
    vector<int> twoSum(vector<int>& vec, int k) {
        unordered_map<int, int> map;
        for (int i = 0; i < vec.size(); ++i) {
            if (map[k - vec[i]]) {
                return {i, map[k - vec[i]] - 1};
            } 
            else {
                map[vec[i]] = i + 1;
            }
        }
        return {};
    }
};
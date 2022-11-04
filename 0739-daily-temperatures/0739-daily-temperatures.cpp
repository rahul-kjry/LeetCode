class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& nums) {
        stack<int> stk;
        vector<int> res(nums.size(), 0);
        for (int i = 0; i < nums.size(); ++i) {
            while (not stk.empty() and nums[i] > nums[stk.top()]) {
                res[stk.top()] = i - stk.top();
                stk.pop();
            }
            stk.push(i);
        }
        return res;
    }
};
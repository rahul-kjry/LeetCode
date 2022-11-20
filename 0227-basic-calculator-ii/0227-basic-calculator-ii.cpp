class Solution {
public:
    int calculate(string str) {
        vector<int> nums;
        vector<char> opts;
        str = " " + str + " ";
        int val = 0;
        for (int i = 1; i < str.size(); ++i) {
            if (isdigit(str[i])) {
                val = val * 10 + (str[i] - '0');
            }
            if (isdigit(str[i - 1]) and not isdigit(str[i])) {
                nums.push_back(val);
                val = 0;
            }
            if (strchr("+-*/", str[i])) {
                opts.push_back(str[i]);
            }
        }
        vector<int> tnums;
        vector<char> topts;
        tnums.push_back(nums[0]);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (opts[i] == '*') {
                tnums[tnums.size() - 1] *= nums[i + 1];
            }
            else if (opts[i] == '/') {
                tnums[tnums.size() - 1] /= nums[i + 1];
            }else {
                tnums.push_back(nums[i + 1]);
                topts.push_back(opts[i]);
            }
        }
        nums = tnums;
        opts = topts;
        tnums.clear();
        topts.clear();
        tnums.push_back(nums[0]);
        for (int i = 0; i < nums.size() - 1; ++i) {
            if (opts[i] == '+') {
                tnums[tnums.size() - 1] += nums[i + 1];
            }
            else if (opts[i] == '-') {
                tnums[tnums.size() - 1] -= nums[i + 1];
            }
        }
        return tnums[0];
    }
};
class Solution {
public:
    int numDecodings(string str) {
        int len = str.size();
        vector<int> dp(len, -1);
        function<int (int)> g = [&](int i) {
            if (i == len) {
                return 1;
            }
            if (dp[i] != -1) {
                return dp[i];
            }
            if (str[i] == '0') {
                return 0;
            }
            int res = g(i + 1);
            if (i < len - 1 and (str[i] == '1' or (str[i] == '2' and str[i + 1] < '7'))) 
                res += g(i + 2);
            return dp[i] = res;
        };
        return g(0);
    }
};
class Solution {
public:
    int dp[10001];
    int numSquares(int n) {
        function<int(int)> g = [&](int tar) {
            if (tar == 0) {
                return 0;
            }
            if (tar < 0) {
                return INT_MAX;
            }
            if (dp[tar] != -1) {
                return dp[tar];
            }
            int min = INT_MAX;
            for (int i = 1; i * i <= tar; ++i) {
                min = fmin(min, 1 + g(tar - i * i));
            }
            return dp[tar] = min;
        };
        memset(dp, -1, sizeof(dp));
        return g(n);
    }
};
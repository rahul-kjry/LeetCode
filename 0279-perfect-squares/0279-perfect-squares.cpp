class Solution {
public:
    int numSquares(int num) {
        vector<int> dp(num + 1, INT_MAX);
        dp[0] = 0;
        int cnt = 1;
        while (cnt * cnt <= num) {
            for (int i = cnt * cnt; i <= num; ++i) {
                dp[i] = min(dp[i], dp[i - cnt * cnt] + 1);
            }
            cnt += 1;
        }
        return dp[num];
    }
};
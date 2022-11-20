class Solution {
public:
    int dp[501][5001];
    int g(int amount, vector<int> & coins, int start) {
        if (amount < 0) {
            return 0;
        }
        if (amount == 0) {
            return 1;
        }
        if (dp[start][amount] != -1) {
            return dp[start][amount];
        }
        int res = 0;
        for (int i = start; i < coins.size(); ++i) {
            res += g(amount - coins[i], coins, i);
        }
        return dp[start][amount] = res;
    }
    
    int change(int amount, vector<int>& coins) {
        memset(dp, -1, sizeof(dp));
        return g(amount, coins, 0);
    }
};
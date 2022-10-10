class Solution {
public:
    vector<vector<int>> dp;
    int g(int i, int j) {
        if (min(i, j) < 0) {
            return 0;
        }
        if (dp[i][j] != -1) return dp[i][j];
        if (i == 0 and j == 0) {
            return 1;
        }
        return dp[i][j] = g(i - 1, j) + g(i, j - 1);
    }
    
    int uniquePaths(int rows, int cols) {
        dp.resize(rows, vector<int>(cols, -1));
        return g(rows - 1, cols - 1);
    }
};
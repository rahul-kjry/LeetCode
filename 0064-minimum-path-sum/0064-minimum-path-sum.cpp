class Solution {
public:
    vector<vector<int>> dp;
    int g(vector<vector<int>> & mat, int i, int j) {
        if (min(i, j) < 0) {
            return INT_MAX;
        }
        if (i == 0 and j == 0) {
            return mat[i][j];
        }
        if (dp[i][j] != -1) return dp[i][j];
        return dp[i][j] = mat[i][j] + min(g(mat, i - 1, j), g(mat, i, j - 1));
    }
    int minPathSum(vector<vector<int>>& mat) {
        dp.resize(mat.size(), vector<int>(mat[0].size(), -1));
        return g(mat, mat.size() - 1, mat[0].size() - 1);
    }
};
class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;
    int g(vector<vector<int>> & mat, int i, int j) {
        if (i == rows or j == cols or mat[i][j]) return 0;
        if (dp[i][j] != -1) return dp[i][j];
        if (i == rows - 1 and j == cols - 1) return 1;
        return dp[i][j] = g(mat, i + 1, j) + g(mat, i, j + 1);
    }
    
    int uniquePathsWithObstacles(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        dp.resize(rows, vector<int>(cols, -1));
        return g(mat, 0, 0);
    }
};
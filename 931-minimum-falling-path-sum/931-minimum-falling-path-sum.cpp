class Solution {
public:
    int res = INT_MAX;
    int rows, cols;
    vector<vector<int>> dp;
    int g(vector<vector<int>> & mat, int i, int j) {
        if (j < 0 or j >= cols) {
            return INT_MAX;
        }
        if (i == rows - 1){
            return mat[i][j];    
        }
        if (dp[i][j] != INT_MAX) return dp[i][j];
        
        return dp[i][j] = mat[i][j] + min({
            g(mat, i + 1, j - 1), 
            g(mat, i + 1, j), 
            g(mat, i + 1, j + 1)
            });
    } 
    int minFallingPathSum(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        dp.resize(rows, vector<int>(cols, INT_MAX));
        for (int j = 0; j < cols; ++j) {
            res = min(res, g(mat, 0, j));
        }
        return res;
    }
};
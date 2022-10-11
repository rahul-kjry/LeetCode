class Solution {
public:
    int rows, cols, mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;
    
    int g(vector<vector<int>> & mat, int i, int j, int sum, int k) {
        if (min(i, j) < 0 or i == rows or j == cols) {
            return 0;
        }
        sum += mat[i][j];
        if (i == rows - 1 and j == cols - 1) {
            return sum % k == 0;
        }
        if (dp[i][j][sum % k] != -1) return dp[i][j][sum % k];
        return dp[i][j][sum % k] = (g(mat, i + 1, j, sum, k) % mod + 
                                    g(mat, i, j + 1, sum, k) % mod) % mod;
    }
    
    int numberOfPaths(vector<vector<int>>& mat, int k) {
        rows = mat.size(), cols = mat[0].size();
        dp.resize(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        return g(mat, 0, 0, 0, k);
    }
};
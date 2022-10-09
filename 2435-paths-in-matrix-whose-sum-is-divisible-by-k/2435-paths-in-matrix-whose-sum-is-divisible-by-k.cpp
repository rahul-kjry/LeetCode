class Solution {
public:
    int rows, cols, rs = 0;
    vector<vector<vector<int>>> dp;
    int md = 1e9 + 7;
    int g(vector<vector<int>>& mat, int i, int j, int sum, int k) {
        if (i == rows || j == cols) return 0;
        sum += mat[i][j];
        if (dp[i][j][sum % k] != -1) return dp[i][j][sum % k];

        if (i == rows - 1 and j == cols - 1) {
            return sum % k == 0;
        }
        return dp[i][j][sum % k] = (g(mat, i + 1, j, sum, k) % md + 
            g(mat, i, j + 1, sum, k) % md) % md;
    }
    
    int numberOfPaths(vector<vector<int>>& mat, int k) {
        rows = mat.size(), cols = mat[0].size();
        dp.resize(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        return g(mat, 0, 0, 0, k);
    }
};
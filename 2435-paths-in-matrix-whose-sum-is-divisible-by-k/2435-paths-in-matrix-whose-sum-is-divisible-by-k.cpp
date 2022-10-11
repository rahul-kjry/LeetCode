class Solution {
public:
    int numberOfPaths(vector<vector<int>>& mat, int k) {
        int rows = mat.size(), cols = mat[0].size(), mod = 1e9 + 7;
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(k, -1)));
        function<int(int, int, int, int)> g = [&](int i, int j, int sum, int k){
            if (min(i, j) < 0 or i == rows or j == cols) {
                return 0;
            }
            sum += mat[i][j];
            if (i == rows - 1 and j == cols - 1) {
                return (sum % k == 0 ? 1 : 0);
            }
            if (dp[i][j][sum % k] != -1) return dp[i][j][sum % k];
            return dp[i][j][sum % k] = (g(i + 1, j, sum, k) % mod + 
                                        g(i, j + 1, sum, k) % mod) % mod;
        };
        return g(0, 0, 0, k);
    }
};
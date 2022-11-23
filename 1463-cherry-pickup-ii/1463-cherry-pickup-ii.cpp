class Solution {
public:
    int rows, cols;
    int dp[71][71][71];
    int cherryPickup(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        memset(dp, -1, sizeof(dp));
        function<int(int, int, int)> g = [&](int i, int j1, int j2) {
            if (min(j1, j2) < 0 or max(j1, j2) >= cols or i == rows) {
                return 0;
            }
            if (dp[i][j1][j2] != -1) {
                return dp[i][j1][j2];
            }
            int res = mat[i][j1] + ((j1 != j2) * mat[i][j2]), mx = 0;
            for (int tj1 = j1 - 1; tj1 <= j1 + 1; ++tj1) {
                for (int tj2 = j2 - 1; tj2 <= j2 + 1; ++tj2) {
                    if (min(tj1, tj2) >= 0 and max(tj1, tj2) < cols) {
                        mx = max(mx, g(i + 1, tj1, tj2));
                    }
                }
            }
            return dp[i][j1][j2] = res + mx;
        };
        return g(0, 0, cols - 1);
    }
};
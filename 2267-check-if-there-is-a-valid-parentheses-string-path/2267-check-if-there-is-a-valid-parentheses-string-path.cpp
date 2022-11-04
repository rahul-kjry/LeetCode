class Solution {
public:
    int rows, cols;
    int dp[101][101][205];
    bool g(vector<vector<char>> & mat, int i, int j, int bal) {
        if (i == rows or j == cols) {
            return 0;
        }
        bal += (mat[i][j] == '(' ? 1 : -1);
        if (bal < 0) {
            return 0;
        }
        if (i == rows - 1 and j == cols - 1 and bal == 0) {
            return 1;
        } 
        if (dp[i][j][bal] != -1) {
            return dp[i][j][bal];
        }
        return dp[i][j][bal] = g(mat, i + 1, j, bal) or g(mat, i, j + 1, bal);
    }
    
    bool hasValidPath(vector<vector<char>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        memset(dp, -1, sizeof(dp));
        return g(mat, 0, 0, 0);
    }
};
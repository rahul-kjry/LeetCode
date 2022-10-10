class Solution {
public:
    int rows, cols;
    vector<vector<int>> dp;
    int g(vector<vector<int>> & mat, int roboR, int roboC, int flagR, int flagC, int zero) {
        if (min(roboR, roboC) < 0 or roboR == rows or roboC == cols or mat[roboR][roboC] == -1) {
            return 0;
        }
        if (roboR == flagR and roboC == flagC) {
            return zero == -1;
        }
        //if (dp[roboR][roboC] != -1) return dp[roboR][roboC];
        mat[roboR][roboC] = -1;
        int res = g(mat, roboR + 1, roboC, flagR, flagC, zero - 1) + 
            g(mat, roboR - 1, roboC , flagR, flagC, zero - 1) + 
            g(mat, roboR, roboC + 1, flagR, flagC, zero - 1) + 
            g(mat, roboR, roboC - 1, flagR, flagC, zero - 1);
        mat[roboR][roboC] = 0;
        return dp[roboR][roboC] = res;
    }
    int uniquePathsIII(vector<vector<int>>& mat) {
        int roboR = -1, roboC = -1, flagR = -1, flagC = -1;
        rows = mat.size(), cols = mat[0].size();
        int zero = 0;
        dp.resize(rows, vector<int>(cols, -1));
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    roboR = i, roboC = j;
                }
                if (mat[i][j] == 2) {
                    flagR = i, flagC = j;
                }
                if (mat[i][j] == 0) ++ zero;
            }
        }
        return g(mat, roboR, roboC, flagR, flagC, zero);
    }
};
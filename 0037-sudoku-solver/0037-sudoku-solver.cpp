class Solution {
public:
    int row[9], col[9], box[9];
    bool g(vector<vector<char>> & mat, int a) {
        if (a == 81) {
            return true;
        }
        int r = a / 9, c = a % 9;
        if (mat[r][c] != '.') {
            return g(mat, a + 1);
        }
        for (int i = 1; i < 10; ++i) {
            if (row[r] & (1 << i) or col[c] & (1 << i) or box[(r / 3) * 3 + (c / 3)] & (1 << i)) {
                continue;
            }
            int tr = row[r], tc = col[c], tb = box[(r / 3) * 3 + (c / 3)];
            row[r] |= (1 << i), col[c] |= (1 << i);
            box[(r / 3) * 3 + (c / 3)] |= (1 << i);
            mat[r][c] = i + '0';
            if (g(mat, a + 1)) {
                return true;
            }
            mat[r][c] = '.', row[r] = tr, col[c] = tc, box[(r / 3) * 3 + (c / 3)] = tb;
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>> & mat) {
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (mat[i][j] != '.') {
                    int val = mat[i][j] - '0';
                    row[i] |= (1 << val);
                    col[j] |= (1 << val);
                    box[(i / 3) * 3 + (j / 3)] |= (1 << val);
                }
            }
        }
        g(mat, 0);
    }
};
class Solution {
public:
    int rows, cols, val;
    
    void g(vector<vector<int>> & mat, int i, int j) {
        if (j < 0 or j >= cols) {
            return ;
        }
        if (i == rows) {
            val = j;
            return ;
        }
        if (mat[i][j] == 1 and j + 1 < cols and mat[i][j + 1] == 1) {
            g(mat, i + 1, j + 1);
        }
        if (mat[i][j] == -1 and j - 1 >= 0 and mat[i][j - 1] == -1) {
            g(mat, i + 1, j - 1);
        }
    }
    vector<int> findBall(vector<vector<int>>& mat) {
        rows = mat.size(), cols = mat[0].size();
        vector<int> res;
        for (int j = 0; j < cols; ++j) {
            val = -1;
            g(mat, 0, j);
            res.push_back(val);
        }
        return res;
    }
};
class Solution {
public:
    int islandPerimeter(vector<vector<int>>& mat){
        int res = 0;
        int os[5] = {0, -1, 0, 1, 0};
        int rows = mat.size(), cols = mat[0].size();
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (mat[i][j] == 1) {
                    if (i == 0) ++ res;
                    if (i == rows - 1) ++ res;
                    if (j == 0) ++ res;
                    if (j == cols - 1) ++ res;
                    if (i > 0) {
                        if (mat[i - 1][j] == 0) ++ res;
                    }
                    if (j > 0) {
                        if (mat[i][j - 1] == 0) ++ res;
                    }
                    if (i < rows - 1) {
                        if (mat[i + 1][j] == 0) ++ res;
                    }
                    if (j < cols - 1) {
                        if (mat[i][j + 1] == 0) ++ res;
                    }
                }
            }
        }
        return res;
    }
};
class Solution {
public:
    bool isValidSudoku(vector<vector<char>> & mat) {
        vector<int> rows(9), cols(9), boxs(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (mat[i][j] == '.') 
                    continue;
                int msk = 1 << (mat[i][j] & 0xf);
                int a = i / 3 * 3 + j / 3;
                if (rows[i] & msk or cols[j] & msk or boxs[a] & msk)
                    return false;
                rows[i] ^= msk, cols[j] ^= msk, boxs[a] ^= msk;
            }
        }
        return true;
    }
};
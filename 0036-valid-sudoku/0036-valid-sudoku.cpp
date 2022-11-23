class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& mat) {
        vector<int> rows(9), cols(9), box(9);
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (mat[i][j] == '.') 
                    continue;
                int msk = 1 << (mat[i][j] & 0xf);
                if (rows[i] & msk)
                    return false;
                rows[i] ^= msk;
                if (cols[j] & msk) 
                    return false;
                cols[j] ^= msk;
                if (box[i / 3 * 3 + j / 3] & msk) 
                    return false;
                box[i / 3 * 3 + j / 3] ^= msk;
            }
        }
        return true;
    }
};
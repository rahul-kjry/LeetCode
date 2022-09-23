class Solution {
public:
    int numIslands(vector<vector<char>>& mat) {
        int rows = mat.size(), cols = mat[0].size();
        int res = 0;
        int os[5] = {1, 0, -1, 0 ,1};
        queue<pair<int, int>> que;
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (mat[r][c] == '1') {
                    ++ res;
                    que.push({r, c});
                    mat[r][c] = '0';
                    while (not que.empty()) {
                        auto [p1, p2] = que.front();
                        que.pop();
                        for (int o = 0; o < 4; ++o) {
                            int x = p1 + os[o], y = p2 + os[o + 1];
                            if (min(x, y) < 0 or x >= rows or y >= cols or mat[x][y] == '0') {
                                continue;
                            }
                            mat[x][y] = '0';
                            que.push({x, y});
                        }
                    }
                }
            }
        }
        return res;
    }
};
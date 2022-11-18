class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int os[5] = {0, -1, 0, 1, 0};
        int rows = grid.size(), cols = grid[0].size();
        int isLandsCount = 0;
        queue<pair<int, int>> que;
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                if (grid[i][j] == '1')  {
                    grid[i][j] = '0';
                    que.push({i, j});
                    ++ isLandsCount;
                    while (not que.empty()) {
                        auto [p1, p2] = que.front();
                        que.pop();
                        for (int o = 0; o < 4; ++o) {
                            int tr = p1 + os[o];
                            int tc = p2 + os[o + 1];
                            if (min(tr, tc) >= 0 and tr < rows and tc < cols and grid[tr][tc] == '1') {
                                grid[tr][tc] = '0';
                                que.push({tr, tc});
                            }
                        }
                    }
                }
            }
        }
        return isLandsCount;
    }
};
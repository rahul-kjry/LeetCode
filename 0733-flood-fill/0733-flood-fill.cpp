class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int os[5] = {0, -1, 0, 1, 0};
        int rows = image.size(), cols = image[0].size();
        int sourceColor = image[sr][sc];
        if (sourceColor == color) {
            return image;
        }
        queue<pair<int, int>> que;
        que.push({sr, sc});
        image[sr][sc] = color;
        while (not que.empty()) {
            auto [r, c] = que.front();
            que.pop();
            for (int o = 0; o < 4; ++o) {
                int tr = r + os[o];
                int tc = c + os[o + 1];
                if (min(tr, tc) >= 0 and tr < rows and tc < cols and image[tr][tc] == sourceColor) {
                    image[tr][tc] = color;
                    que.push({tr, tc});
                }
            }
        }
        return image;
    }
};
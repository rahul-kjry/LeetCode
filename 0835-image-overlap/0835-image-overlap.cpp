class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        map<pair<int, int>, int> mp;
        vector<pair<int, int>> vp1, vp2;
        int res = 0;
        int len = img1.size();
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (img1[i][j])
                    vp1.push_back({i, j});
                if (img2[i][j]) 
                    vp2.push_back({i, j});
            }
        }
        for (auto & [ff, fs] : vp1) {
            for (auto & [sf, ss] : vp2) {
                res = max(res, ++ mp[{ff - sf, fs - ss}]);
            }
        }
        return res;
    }
};
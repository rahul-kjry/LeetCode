class Solution {
public:    
    int res = 0, len, ilen;
    vector<bool> viz;
    void g(vector<vector<int>> & std, vector<vector<int>> & mnt, int i, int ans) {
        if (i == len) {
            res = max(res, ans);
            return ;
        }
        for (int j = 0; j < len; ++j) {
            if (viz[j] == true) {
                continue;
            }
            viz[j] = true;
            int cmpt = 0;
            for (int k = 0; k < ilen; ++k) {
                cmpt += (std[i][k] == mnt[j][k]);
            }
            g(std, mnt, i + 1, ans + cmpt);
            viz[j] = false;
        }
        
    }
    
    int maxCompatibilitySum(vector<vector<int>>& std, vector<vector<int>>& mnt) {
        len = std.size(), ilen = std[0].size();
        viz.resize(len, false);
        g(std, mnt, 0, 0);
        return res;
    }
};
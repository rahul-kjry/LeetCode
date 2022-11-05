class Solution {
public:
    vector<int> findSmallestSetOfVertices(int len, vector<vector<int>>& edg) {
        vector<bool> viz(len);
        for (vector<int> & i : edg) {
            viz[i[1]] = true;
        }
        vector<int> res;
        for (int i = 0; i < len; ++i) {
            if (not viz[i]) {
                res.push_back(i);
            }
        }
        return res;
    }
    
};
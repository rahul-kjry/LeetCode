class Solution {
public:
    vector<vector<int>> ans;
    void g(vector<int> & cnd, int tgt, int ind, vector<int> cur) {
        if (0 > tgt) {
            return ;
        }
        if (0 == tgt) {
            ans.push_back(cur);
            return ;
        } 
        for (int i = ind; i < cnd.size(); ++i) {
            cur.push_back(cnd[i]);
            g(cnd, tgt - cnd[i], i, cur);
            cur.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& cnd, int tgt) {
        vector<int> cur;
        g(cnd, tgt, 0, cur);
        return ans;
    }
};
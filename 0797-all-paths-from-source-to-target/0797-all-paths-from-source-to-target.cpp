class Solution {
public:
    vector<vector<int>> res;
    
    void g(vector<vector<int>>& grp, vector<int> & vec, int i) {
        vec.push_back(i);
        if (i == grp.size() - 1) {
            res.push_back(vec);
        }
        else for (int & j : grp[i]) {
            g(grp, vec, j);
        }
        vec.pop_back();
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& grp) {
        vector<int> vec;
        g(grp, vec, 0);
        return res;
    }
};
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& itv) {
        sort(itv.begin(), itv.end(), [](auto & p1, auto & p2) {
            return p1[0] < p2[0];
        });
        vector<vector<int>> res(itv.begin(), itv.begin() + 1);
        itv.erase(itv.begin());
        for (auto & cur : itv) {
            auto & pre = res.back();
            if (cur[0] <= pre[1]) {
                pre[1] = max(pre[1], cur[1]);
            }
            else {
                res.push_back(cur);
            }
        }
        return res;
    }
};
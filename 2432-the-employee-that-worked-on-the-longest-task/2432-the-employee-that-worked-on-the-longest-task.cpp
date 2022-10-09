class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        unordered_set<int> st;
        int res = logs[0][0], max = logs[0][1], cur = 0;
        for (int i = 0; i < logs.size(); ++i) {
            int v1 = logs[i][0], v2 = logs[i][1];
            int cur = 0;
            for (int j = min(cur, (i == 0 ? 0 : v1)); j < v2; ++j) {
                if (st.find(j) == st.end()) {
                    st.insert(j);
                    ++ cur;
                }
            }
            cout << i << " " << cur << "\n";
                if (cur > max) {
                    max = cur;
                    res = v1;
                } else if (cur == max) {
                    res = fmin(v1, res);
                }
            cur = fmax(v2, cur);
        }
        return res;
    }
};
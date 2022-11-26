class Solution {
public:
    int jobScheduling(vector<int>& st, vector<int>& ed, vector<int>& pr) {
        vector<vector<int>> vc;
        int ln = st.size();
        vector<int> dp(ln, -1);
        for (int i = 0; i < ln; ++i) 
            vc.push_back({st[i], ed[i], pr[i]});
        sort(vc.begin(), vc.end());
        function<int(int)> g = [&](int i) {
            if (i >= ln) {
                return 0;
            }
            if (dp[i] != -1) return dp[i];
            int lo = i + 1, hi = ln - 1, ni = ln;
            while (lo <= hi) {
                int md = lo + (hi - lo) / 2;
                if (vc[md][0] >= vc[i][1]) {
                    ni = md;
                    hi = md - 1;
                }
                else {
                    lo = md + 1;
                }
            }
            return dp[i] = max(g(i + 1), g(ni) + vc[i][2]);
        };
        return g(0);
    }
};
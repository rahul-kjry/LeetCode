class Solution {
public:
    #define pi pair<int, int>
    int minCostConnectPoints(vector<vector<int>>& points) {
        int len = points.size();
        int res = 0;
        vector<pi> adj[len + 1];
        vector<bool> viz(len + 1, false);
        for (int i = 0; i < len; ++i) {
            for (int j = 0; j < len; ++j) {
                if (i != j ) {
                    adj[i].push_back({j, abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1])});
                }
            }
        }
        priority_queue<pi, vector<pi>, greater<pi>> pq;
        pq.push({0, 0});
        while (not pq.empty()) {
            auto [p1, p2] = pq.top();
            pq.pop();
            if (viz[p2]) {
                continue;
            }
            viz[p2] = true;
            res += p1;
            for (auto [p3, p4] : adj[p2]) {
                if (viz[p3] == false) {
                    pq.push({p4, p3});
                }
            }
        }
        return res;
    }
};
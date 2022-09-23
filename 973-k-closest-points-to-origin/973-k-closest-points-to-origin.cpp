class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& pts, int k) {
        priority_queue<pair<double, pair<int,int>>> pq;
        for (auto & i : pts) {
            pq.push({sqrt(i[0] * i[0] + i[1] * i[1]), {i[0], i[1]}});
        }
        while (pq.size() > k) {
            pq.pop();
        }
        vector<vector<int>> res;
        while (not pq.empty()) {
            res.push_back({pq.top().second.first, pq.top().second.second});
            pq.pop();
        }
        return res;
    }
};
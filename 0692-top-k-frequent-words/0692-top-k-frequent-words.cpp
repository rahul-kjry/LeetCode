class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> map;
        for (string & word : words) ++ map[word];
        vector<pair<string, int>> vec;
        for (auto & [k, v] : map) {
            vec.push_back({k, v});
        }
        sort(vec.begin(), vec.end(), 
            [](pair<string, int> & p1, pair<string, int> & p2){
                if (p1.second == p2.second) {
                    return p1.first < p2.first;
                }
                else {
                    return p1.second > p2.second;
                }
            });
        for (auto & i : vec) {
            cout << i.first << " " << i.second << "\n";
        }
        vector<string> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(vec[i].first);
        }
        return res;
    }
};
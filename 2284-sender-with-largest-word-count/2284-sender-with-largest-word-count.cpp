class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> map;
        for (int i = 0; i < senders.size(); ++i) {
            map[senders[i]] += count(messages[i].begin(), messages[i].end(), ' ') + 1;
        }
        vector<pair<string, int>> vec;
        for (auto & [k, v] : map) vec.push_back({k, v});
        sort(vec.begin(), vec.end(), 
            [](pair<string, int> & p1, pair<string, int> & p2){
                if (p1.second == p2.second) {
                    return p1.first > p2.first;
                } 
                else {
                    return p1.second > p2.second;
                }
            });
        return vec[0].first;
    }
};
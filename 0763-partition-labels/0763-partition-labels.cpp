class Solution {
public:
    #define fir first
    #define sec second
    vector<int> partitionLabels(string str) {
        unordered_map<char, pair<int, int>> mp;
        for (int i = 0; i < str.size(); ++i) {
            if (mp.find(str[i]) != mp.end()) {
                mp[str[i]].fir = min(i, mp[str[i]].fir);
                mp[str[i]].sec = max(i, mp[str[i]].sec);
            }
            else {
                mp[str[i]].fir = i;
                mp[str[i]].sec = i;
            }
        }
        vector<pair<int, int>> vec;
        for (auto & [k, v] : mp) {
            vec.push_back(v);
        }
        sort(vec.begin(), vec.end());
        vector<int> res;
        int pa = vec[0].fir;
        int pb = vec[0].sec;
        for (auto & [p1, p2] : vector<pair<int, int>>(vec.begin() + 1, vec.end())) {
            if (p1 <= pb) {
                pb = max(pb, p2);
            }
            else {
                res.push_back(pb - pa + 1);
                pa = p1;
                pb = p2;
            }
        }
        res.push_back(pb - pa + 1);
        return res;
    }
};
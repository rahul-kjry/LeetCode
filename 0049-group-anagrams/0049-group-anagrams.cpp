class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        vector<vector<string>> res;
        for (string & str : strs) {
            map<char, int> tmp;
            for (char & ch : str) {
                ++ tmp[ch];
            }
            mp[tmp].push_back(str);
        }
        for (auto & [k, v] : mp) {
            res.push_back(v);
        }
        return res;
    }
};
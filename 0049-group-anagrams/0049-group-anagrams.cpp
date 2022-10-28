class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<map<char, int>, vector<string>> mp;
        for (string & str : strs) {
            map<char, int> tmp;
            for (char & ch : str) ++tmp[ch];
            mp[tmp].push_back(str);
        }
        vector<vector<string>> res;
        for (auto & [k, v] : mp) {
            vector<string> tres;
            for (string & str : v) {
                tres.push_back(str);
            }
            res.push_back(tres);
        }
        return res;
    }
};
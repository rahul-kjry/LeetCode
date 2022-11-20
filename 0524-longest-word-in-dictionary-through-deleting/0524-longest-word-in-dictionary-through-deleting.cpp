class Solution {
public:
    string findLongestWord(string str, vector<string>& dct) {
        string res = "";
        for (string & wrd : dct) {
            int i = 0, j = 0;
            for (i = 0; i < str.size() and j < wrd.size(); ++i) {
                if (str[i] == wrd[j]) ++j;
            }
            if (j == wrd.size()) {
                if (wrd.size() > res.size()) {
                    res = wrd;
                }
                else if (wrd.size() == res.size()) {
                    res = min(wrd, res);
                }
            }
        }
        return res;
    }
};
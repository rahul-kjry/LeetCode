class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> samLtr, difLtr;
        for (string & wrd : words) {
            if (wrd[0] == wrd[1]) {
                ++samLtr[wrd];
            }
            else {
                ++difLtr[wrd];
            }
        }
        int res = 0;
        for (auto & [k, v] : difLtr) {
            string ftmp = k;
            string rtmp = string(ftmp.rbegin(), ftmp.rend());
            if (difLtr[ftmp] and difLtr[rtmp]) {
                res += min(difLtr[ftmp], difLtr[rtmp]) * 4;
                difLtr[ftmp] = 0;
                difLtr[ftmp] = 0;
            }
        } 
        bool midVal = false;
        for (auto & [k, v] : samLtr) {
            string tmp = k;
            if (samLtr[tmp]) {
                if (samLtr[tmp] & 1 ^ 1) {
                    res += samLtr[tmp] * 2;
                }
                else {
                    midVal = true;
                    res += (samLtr[tmp] - 1) * 2;
                }
            }
        }
        if (midVal) res += 2;
        return res;
        
    }
};
class Solution {
public:
    string reverseWords(string str) {
        stringstream ss(str);
        string wrd, res;
        while (ss >> wrd) {
            res = wrd + " " + res;
        }
        res.pop_back();
        return res;
    }
};
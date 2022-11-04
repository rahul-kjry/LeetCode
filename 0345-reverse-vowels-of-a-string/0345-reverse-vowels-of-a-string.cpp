class Solution {
public:
    bool isvow(char & ch) {
        return strchr("aeiou", tolower(ch));
    }
    string reverseVowels(string str) {
        int lo = 0, hi = str.size() - 1;
        while (lo < hi) {
            while (not isvow(str[lo]) and lo < hi) ++lo;
            while (not isvow(str[hi]) and lo < hi) --hi;
            if (isvow(str[lo]) and isvow(str[hi])) {
                swap(str[lo], str[hi]);
                ++lo; --hi;
            }
        }
        return str;
    }
};
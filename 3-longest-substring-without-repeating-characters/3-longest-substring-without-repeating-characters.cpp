class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int lo = 0, hi = 0;
        int rs = 0, ln = s.size();
        while (hi < ln) {
            ++ mp[s[hi]];
            while (mp[s[hi]] > 1) {
                -- mp[s[lo ++]];
            }
            rs = max(rs, hi - lo + 1);
            ++ hi;
        }
        return rs;
    }
};
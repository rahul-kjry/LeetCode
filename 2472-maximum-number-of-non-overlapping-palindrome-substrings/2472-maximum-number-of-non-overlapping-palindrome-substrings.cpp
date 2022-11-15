class Solution {
public:
    bool pal(string & str, int lo, int hi) {
        while (lo < hi) {
            if (str[lo++] != str[hi--]) {
                return false;
            }
        }
        return true;
    }
    
    int maxPalindromes(string str, int k) {
        int len = str.size();
        vector<int>dp(len + 1, 0);
        for (int i = k - 1; i < len; ++i) {
            dp[i + 1] = dp[i];
            if (pal(str, i - k + 1, i)) {
                dp[i + 1] = max(dp[i + 1], 1 + dp[i - k + 1]);
            }
            if (i - k >= 0 and pal(str, i - k, i)) {
                dp[i + 1] = max(dp[i + 1], 1 + dp[i - k]);
            }
        }
        return dp[len];
    }
};
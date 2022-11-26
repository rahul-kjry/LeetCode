class Solution {
public:
    int dp[10001][11][11][6];
    int mod = 1e9+7;
    int g(string & str, int id, int fi, int se, int ct) {
        if (ct == 5) {
            return 1;
        }
        if (id == str.size()) {
            return 0;
        }
        if (dp[id][fi][se][ct] != -1) {
            return dp[id][fi][se][ct];
        }
        int res = g(str, id + 1, fi, se, ct) % mod;
        if (ct == 0) {
            res += g(str, id + 1, str[id] - '0', se, ct + 1);
            res %= mod;
        }
        if (ct == 1) {
            res += g(str, id + 1, fi, str[id] - '0', ct + 1);
            res %= mod;
        }
        if (ct == 2) {
            res += g(str, id + 1, fi, se, ct + 1);
            res %= mod;
        }
        if (ct == 3) {
            if (se == str[id] - '0') {
                res += g(str, id + 1, fi, se, ct + 1);
            res %= mod;
            }
        }
        if (ct == 4) {
            if (fi == str[id] - '0') {
                res += g(str, id + 1, fi, se, ct + 1);
            res %= mod;
            }
        }
        return dp[id][fi][se][ct] = res % mod;
    }
    
    int countPalindromes(string str) {
        memset(dp, -1, sizeof(dp));
        return g(str, 0, 0, 0, 0);
    }
};
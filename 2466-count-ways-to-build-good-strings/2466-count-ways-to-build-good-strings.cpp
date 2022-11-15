class Solution {
public:
    const int mod = 1e9 + 7;
    vector<int> dp;
    long long g(int val, int lo, int hi, int zero, int ones) {
        if (val > hi) {
            return 0;
        }
        if (dp[val] != -1) {
            return dp[val];
        }
   
        long long may1 = g(val + zero, lo, hi, zero, ones) % mod;
        long long may2 = g(val + ones, lo, hi, zero, ones) % mod;
        return dp[val] = ((val >= lo and val <= hi) + may1 + may2) % mod;
    }
    
    int countGoodStrings(int lo, int hi, int zero, int ones) {
        dp.resize(hi + 1, -1);
        return g(0, lo, hi, zero, ones);;
 
    }
};
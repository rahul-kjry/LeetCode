class Solution {
public:
    int rlen, flen;
    #define ll long long
    ll dp[101][101][101];
    ll g(vector<int>& rbt, vector<vector<int>>& fct, int ri, int fi, int lim) {
        if (ri >= rlen) return 0;
        if (fi >= flen) return 1e18;
        if(dp[ri][fi][lim] != -1) return dp[ri][fi][lim];
        ll ans = 1e18; 
        if(lim > 0) {
            ans = g(rbt, fct, ri + 1, fi, lim - 1) + abs(rbt[ri] - fct[fi][0]);
        }
        if(fi + 1 < flen) {
            ans = min(ans, g(rbt, fct, ri, fi + 1, fct[fi + 1][1]));
        }
        return dp[ri][fi][lim] = ans;
    }
    
    long long minimumTotalDistance(vector<int>& rbt, vector<vector<int>>& fct) {
        sort(rbt.begin(), rbt.end());
        sort(fct.begin(), fct.end());
        rlen = rbt.size(), flen = fct.size();
        memset(dp, -1, sizeof(dp));
        return g(rbt, fct, 0, 0, fct[0][1]);
    }
};
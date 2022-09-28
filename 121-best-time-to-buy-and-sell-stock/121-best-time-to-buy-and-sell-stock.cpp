class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int mn = INT_MAX, ans = 0;
        for(int i = 0; i < len; ++i){
            mn = min(mn, prices[i]);
            ans = max(ans, prices[i]-mn);
        }
        return ans;
    }
};
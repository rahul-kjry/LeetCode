class StockSpanner {
public:
    #define val first
    #define cnt second
    stack<pair<int, int>> stk;
    StockSpanner() {
        
    }
    
    int next(int prc) {
        int sum = 0, res = 1;
        while (not stk.empty() and stk.top().val <= prc) {
            res += stk.top().cnt;
            stk.pop();
        }
        stk.push({prc, res});
        return res;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
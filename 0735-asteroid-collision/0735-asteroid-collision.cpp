class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        stack<int> stk;
        for (int & val : ast) {
            if (stk.empty() or stk.top() < 0 or val >= 0) {
                stk.push(val);
            } 
            else {
                int opt = -1;
                while (not stk.empty() and val < 0 and stk.top() > 0) {
                    opt = -1;
                    if (abs(val) == stk.top()) {
                        opt = 0;
                        stk.pop();
                        break;
                    }
                    else if (abs(val) > stk.top()) {
                        opt = 1;
                        stk.pop();
                    }
                    else {
                        int opt = 2;
                        break;
                    }
                }
                if (opt == 1) stk.push(val);
            }
        }
        vector<int> res;
        while (not stk.empty()) {
            res.push_back(stk.top());
            stk.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& ast) {
        vector<int> stk;
        for (int & val : ast) {
            if (stk.empty() or stk.back() < 0 or val >= 0) {
                stk.push_back(val);
            } 
            else {
                bool flag = false;
                while (not stk.empty() and val < 0 and stk.back() > 0) {
                    flag = false;
                    if (abs(val) == stk.back()) {
                        stk.pop_back();
                        break;
                    }
                    else if (abs(val) > stk.back()) {
                        flag = true;
                        stk.pop_back();
                    }
                    else {
                        break;
                    }
                }
                if (flag) stk.push_back(val);
            }
        }
        return stk;
    }
};
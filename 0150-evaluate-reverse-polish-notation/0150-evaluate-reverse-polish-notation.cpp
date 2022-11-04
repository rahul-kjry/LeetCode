class Solution {
public:
    
    bool isOp(string & str) {
        return strstr("+-*/", str.c_str());
    }
    
    int evalRPN(vector<string>& tokens) {
        stack<long long> stk;
        for (string & str : tokens) {
            if (isOp(str)) {
                long long val1 = stk.top(); stk.pop();
                long long val2 = stk.top(); stk.pop();
                if (str == "+"){
                    stk.push(val1 + val2);
                }
                else if (str == "-") {
                    stk.push(val2 - val1);
                }
                else if (str == "*") {
                    stk.push(val1 * val2);
                }
                else if (str == "/") {
                    stk.push(val2 / val1);
                }
            }
            else {
                stk.push(stoll(str));
            }
        }
        return stk.top();
    }
};
class Solution {
public:
    bool checkValidString(string str) {
        stack<int> opn, ast;
        for (int i = 0 ; i < str.size(); ++i) {
            if (str[i] == '(') {
                opn.push(i);
            }
            else if (str[i] == '*') {
                ast.push(i);
            }
            else {
                if (not opn.empty()) {
                    opn.pop();
                }
                else if (not ast.empty()) {
                    ast.pop();
                }
                else {
                    return false;
                }
            }
        }
        while (not opn.empty() and not ast.empty()) {
            if (opn.top() > ast.top()) {
                return false;
            }
            opn.pop();
            ast.pop();
        }
        return opn.empty();
    }
};
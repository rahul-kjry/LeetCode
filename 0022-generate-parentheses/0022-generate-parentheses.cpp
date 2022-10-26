class Solution {
public:
    vector<string> res;
    
    bool valid(string & str) {
        int bal = 0;
        for (char & ch : str) {
            bal += (ch == '(' ? 1 : -1);
            if (bal < 0) {
                return false;
            }
        }
        return bal == 0;
    }
    
    void g(int len, string str = "") {
        if (str.size() == 2 * len) {
            if (valid(str)) {
                res.push_back(str);
            }
            return ;
        }
        str.push_back('(');
        g(len, str);
        str.pop_back();
        str.push_back(')');
        g(len, str);
        str.pop_back();
    }
    
    vector<string> generateParenthesis(int len) {
        g(len);
        return res;
    }
};
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
    
    void g(int len, string str, int lft, int rgt) {
        if (str.size() == 2 * len) {
            if (valid(str)) {
                res.push_back(str);
            }
            return ;
        }
        if (lft < len) {
            str.push_back('(');
            g(len, str, lft + 1, rgt);
            str.pop_back();
        }
        if (rgt < lft) {
            str.push_back(')');
            g(len, str, lft, rgt + 1);
            str.pop_back();
        }
    }
    
    vector<string> generateParenthesis(int len) {
        g(len, "", 0, 0);
        return res;
    }
};
class Solution {
public:
    string removeDuplicates(string str) {
        string res;
        for (char & ch : str) {
            if (res.empty() or res.back() != ch) {
                res.push_back(ch);
            }
            else {
                res.pop_back();
            }
        }
        return res;
    }
};
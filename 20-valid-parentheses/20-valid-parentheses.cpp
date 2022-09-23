class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> mp;
        mp['{'] = '}';
        mp['('] = ')';
        mp['['] = ']';
        stack<char> stk;
        for (char & ch : s) {
            if (strchr("[{(", ch)) {
                stk.push(ch);
            } 
            else if(not stk.empty() and mp[stk.top()] == ch) {
                stk.pop();
            }  
            else {
                return false;
            }
        }
        return stk.empty();
    }
};
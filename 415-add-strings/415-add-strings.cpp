class Solution {
public:
    string addStrings(string s1, string s2) {
        string ans;
        int carry = 0;
        reverse(s1.begin(), s1.end());
        reverse(s2.begin(), s2.end());
        while (not s1.empty() or not s2.empty() or carry) {
            int sum =  (not s1.empty() ? stoi(s1.substr(0,1)) : 0) +
                (not s2.empty() ? stoi(s2.substr(0,1)) : 0) + carry;
            ans = to_string(sum % 10) + ans;
            carry = sum / 10;
            s1 = (not s1.empty() ? s1.substr(1) : s1);
            s2 = (not s2.empty() ? s2.substr(1) : s2);
        }
        return ans;
    }
};
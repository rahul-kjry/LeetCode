class Solution {
public:
    string countAndSay(int n) {
        string str = "1";
        for (int i = 1; i < n; ++i) {
            string res = "";
            char chr = str[0];
            int cnt = 1;
            for (int j = 1; j < str.size(); ++j) {
                if (str[j] != str[j - 1]) {
                    res += to_string(cnt) + str[j - 1];
                    cnt = 1;
                    chr = str[j];
                }
                else {
                    ++ cnt;
                }
            }
            res += to_string(cnt) + str.back();
            str = res;
        }
        return str;
    }
};
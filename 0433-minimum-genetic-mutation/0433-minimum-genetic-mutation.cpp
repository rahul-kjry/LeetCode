class Solution {
public:
    int minMutation(string stt, string end, vector<string>& bnk) {
        unordered_set<string> st(bnk.begin(), bnk.end());
        queue<string> que;
        que.push(stt);
        int len = 0;
        while (not que.empty()) {
            for (int i = que.size(); i > 0; --i) {
                string cur = que.front();
                que.pop();
                if (cur == end) {
                    return len;
                }
                st.erase(cur);
                for (int j = 0; j < 8; ++j) {
                    char tmp = cur[j];
                    for (char & ch : string("ACGT")) {
                        cur[j] = ch;
                        if (st.find(cur) != st.end()) {
                            que.push(cur);
                        }
                    }
                    cur[j] = tmp;
                }
            }
            len += 1;
        }
        return -1;
    }
};
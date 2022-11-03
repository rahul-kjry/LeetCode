class TrieNode {
    public:
    vector<TrieNode *> child;
    TrieNode() {
        child.resize(26, nullptr);
    }
};

class Solution {
public:
    unordered_map<int, string> mp;
    int maxLen = 0;
    
    void add(TrieNode * root, string & str, int & maxLen, string & maxWrd) {
        int len = str.size(), curLen = 0;
        string curWrd = "";
        for (int i = 0; i < len; ++i) {
            if (root -> child[str[i] - 'a'] == nullptr) {
                if (i == len - 1) {
                    root -> child[str[i] - 'a'] = new TrieNode();
                }
                else {
                    break;
                }
            }
            root = root -> child[str[i] - 'a'];
            curWrd += str[i];
            ++ curLen;
        }
        if (curLen > maxLen) {
            maxLen = curLen;
            maxWrd = curWrd;
        }
        if (curLen == maxLen) {
            maxWrd = min(curWrd, maxWrd);
        }
    }
    
    string longestWord(vector<string>& words) {
        TrieNode * root = new TrieNode();
        sort(words.begin(), words.end(), [](string & a, string & b) {
            if (a.size() == b.size()) {
                return a > b;
            }
            else {
                return a.size() < b.size();
            }
        });
        int maxLen = 0;
        string maxWrd = "";
        for (string & str : words) {
            add(root, str, maxLen, maxWrd);
        }
        for (auto & [k, v] : mp) {
            cout << k << " " << v << endl;
        }
        return maxWrd;
    }
};
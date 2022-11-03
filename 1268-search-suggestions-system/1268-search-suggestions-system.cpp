class TrieNode {
    public:
    vector<TrieNode *> child;
    bool isEnd;
    TrieNode() {
        child.resize(26, nullptr);
        isEnd = false;
    }
};

class Solution {
public:
    
    void insert(string & str, TrieNode * tmp) {
        for (char & ch : str) {
            if (tmp -> child[ch - 'a'] == NULL) {
                tmp -> child[ch - 'a'] = new TrieNode;
            }
            tmp = tmp -> child[ch - 'a'];
        }
        tmp -> isEnd = true;
    }
    
    void dfs(TrieNode * tmp, string & pre, vector<string> & vec) {
        if (vec.size() == 3) {
            return;
        }
        if (tmp -> isEnd) {
            vec.push_back(pre);
        }
        for (char ch = 'a'; ch <= 'z'; ++ch) {
            if (tmp -> child[ch - 'a']) {
                pre.push_back(ch);
                dfs(tmp -> child[ch - 'a'], pre, vec);
                pre.pop_back();
            }
        }
    }
    
    void get(TrieNode * tmp, string & pre, vector<string> & vec) {
        vector<string> res;
        for (char & ch : pre) {
            if (tmp -> child[ch - 'a'] == NULL) {
                return ;
            }
            tmp = tmp -> child[ch - 'a'];
        }
        dfs(tmp, pre, vec);
    }
    
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        TrieNode * root = new TrieNode();
        for (string & wrd : products) {
            insert(wrd, root);
        }
        vector<vector<string>> res;
        string pre;
        for (char & ch : searchWord) {
            pre.push_back(ch);
            vector<string> vec;
            get(root, pre, vec);
            res.push_back(vec);
        }
        return res;
    }
};
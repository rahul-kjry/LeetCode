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
    
    void insert(TrieNode * root, string & str) {
        for (char & ch : str) {
            if (root -> child[ch - 'a'] == nullptr) {
                root -> child[ch - 'a'] = new TrieNode();
            }
            root = root -> child[ch - 'a'];
        }
        root -> isEnd = true;
    }
    
    string get(TrieNode * root, string & str) {
        string ans;
        for (char & ch : str) {
            if (root -> isEnd) {
                return ans;
            }
            ans.push_back(ch);
            if (root -> child[ch - 'a'] == nullptr) {
                return str;
            }
            
            root = root -> child[ch - 'a'];
        }
        return str;
    }
    
    string replaceWords(vector<string>& dictionary, string sentence) {
        TrieNode * root = new TrieNode();
        for (string & wrd : dictionary) {
            insert(root, wrd);
        }
        vector<string> words;
        sentence += ' ';
        string wrd, res = "";
        for (char & ch : sentence) {
            if (ch == ' ') {
                words.push_back(wrd);
                wrd = "";
            }
            else {
                wrd.push_back(ch);
            }
        }
        for (string & str : words) {
            res += get(root, str) + " ";
            
        }
        if (res.size()) res.pop_back();
        return res;
    }
};
class Solution {
public:
    bool checkIfPangram(string str) {
        return set<char>(str.begin(), str.end()).size() == 26;
    }
};
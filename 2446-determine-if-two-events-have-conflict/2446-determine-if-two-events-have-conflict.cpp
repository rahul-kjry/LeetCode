class Solution {
public:
    
    int g(string & str) {
        return stoi(str.substr(0, 2)) * 60 + stoi(str.substr(3, 2));
    }
    
    bool haveConflict(vector<string>& e1, vector<string>& e2) {
        return max(g(e1[0]), g(e2[0])) <= min(g(e1[1]), g(e2[1]));
    }
};
class Solution {
public:
    int r, c, l;
    map<pair<int,int>, int> mp;
    bool dfs(int i, int j, int a, vector<vector<char>>& board, string word) {
        if(a == l) return true;
        if(i < 0 or i >= r or 
           j < 0 or j >= c or 
           board[i][j] != word[a] or 
           a > l or mp[{i,j}] == 1) 
            return false;
        mp[{i,j}] = 1;
        auto ans = (dfs(i + 1, j, a + 1, board, word) or
            dfs(i - 1, j, a + 1, board, word) or
            dfs(i, j + 1, a + 1, board, word) or
            dfs(i, j - 1, a + 1, board, word));
        mp[{i,j}] = 0;
        return ans;
    }
    bool exist(vector<vector<char>>& board, string word) {
        r = board.size(), c = board[0].size();
        l = word.size();
        for(int i=0; i<r; ++i) {
            for(int j=0; j<c; ++j) {
                if(dfs(i, j, 0, board, word)) 
                    return true;
            }
        }
        return false;
    }
};
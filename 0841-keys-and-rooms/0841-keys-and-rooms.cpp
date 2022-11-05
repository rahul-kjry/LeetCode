class Solution {
public:
    int len;
    vector<int> viz;
    
    void dfs(vector<vector<int>>& rooms, int i) {
        if (viz[i]) {
            return ;
        }
        viz[i] = true;
        for (int & j : rooms[i]) {
            dfs(rooms, j);
        }
    }
    
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        len = rooms.size();
        viz.resize(len, false);
        dfs(rooms, 0);
        for (int i = 0; i < len; ++i) {
            if (not viz[i]) {
                return false;
            }
        }
        return true;
    }
};
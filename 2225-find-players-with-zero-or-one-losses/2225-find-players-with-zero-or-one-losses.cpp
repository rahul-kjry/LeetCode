class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {        
        set<int> st;
        unordered_map<int, int> won, lst;
        for (auto & i : matches) {
            won[i[0]] += 1;
            lst[i[1]] += 1;
            st.insert(i[0]);
            st.insert(i[1]);
        }
        vector<vector<int>> res(2);
        for (int i : st) {
            if (lst[i] == 0) res[0].push_back(i);
            if (lst[i] == 1) res[1].push_back(i);
        }
        return res;
    }
};
class Solution {
public: 
    map<string, multiset<string>> adj;
    vector<string> route;
    
    void dfs(string src) {
        while (not adj[src].empty()) {
            string next = *adj[src].begin();
            adj[src].erase(adj[src].begin());
            dfs(next);
        }
        route.push_back(src);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto & i : tickets) {
            adj[i[0]].insert(i[1]);
        }
        dfs("JFK");
        return vector<string>(route.rbegin(), route.rend());
    }
};
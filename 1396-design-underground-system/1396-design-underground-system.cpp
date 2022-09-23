class UndergroundSystem {
public:
    map<int, pair<string, int>> mp1;
    map<pair<string, string>, vector<int>> mp2;
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        mp1[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        mp2[{mp1[id].first, stationName}].push_back(t - mp1[id].second);
    }
    
    double getAverageTime(string startStation, string endStation) {
        double rs = 0.0, ln = 0.0;
        for (auto & i : mp2[{startStation ,endStation}]) {
            rs += i;
            ++ ln;
        }
        return rs / ln;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
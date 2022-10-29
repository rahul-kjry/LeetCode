class Solution {
public:
    #define F first
    #define S second
    #define pi pair<int, int>
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pi> vp;
        for (int i = 0; i < pt.size(); ++i)
            vp.push_back({pt[i], gt[i]});
        sort(vp.begin(), vp.end(), [](const pi & v1, const pi & v2){
                 return v1.S == v2.S ? v1.F < v2.F : v1.S > v2.S; });
        int pre(0), res(0);
        for (auto & i : vp)
            res = fmax(res, (pre += i.F) + i.second);
        return res;
    }
};
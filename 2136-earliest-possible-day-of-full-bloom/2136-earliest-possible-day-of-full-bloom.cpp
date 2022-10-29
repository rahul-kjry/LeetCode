class Solution {
public:
    int earliestFullBloom(vector<int>& pt, vector<int>& gt) {
        vector<pair<int, int>> vp;
        int len = pt.size();
        for (int i = 0; i < len; ++i) {
            vp.push_back({pt[i], gt[i]});
        }
        sort(vp.begin(), vp.end(), 
             [](const pair<int, int> & val1, const pair<int, int> & val2){
                 if (val1.second == val2.second) {
                     return val1.first < val2.first;
                 }
                 else {
                     return val1.second > val2.second;
                 }
             });
        int pre = 0, res = 0;
        for (auto & i : vp) {
            pre += i.first;
            res = fmax(res, pre + i.second);
        }
        return res;
    }
};
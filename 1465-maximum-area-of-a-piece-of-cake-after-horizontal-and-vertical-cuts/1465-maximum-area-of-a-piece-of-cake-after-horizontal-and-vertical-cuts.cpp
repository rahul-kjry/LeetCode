class Solution {
public:
    int maxArea(int h, int v, vector<int>& hor, vector<int>& vrt) {
        sort(hor.begin(), hor.end());
        sort(vrt.begin(), vrt.end());
        hor.insert(hor.begin(), 0);
        vrt.insert(vrt.begin(), 0);
        hor.push_back(h);
        vrt.push_back(v);
        unsigned long long int horMaxDif = 0;
        unsigned long long int vrtMaxDif = 0;
        for (int i = 0; i < hor.size() - 1; ++i) {
            horMaxDif = fmax(horMaxDif, hor[i + 1] - hor[i]);
        }
        for (int i = 0; i < vrt.size() - 1; ++i) {
            vrtMaxDif = fmax(vrtMaxDif, vrt[i + 1] - vrt[i]);
        }
        return (horMaxDif * vrtMaxDif) % 1000000007;
    }
};
class Solution {
public:
    #define pi pair<int, int>
    #define fir first
    #define sec second
    long long totalCost(vector<int>& nums, int k, int c) {
        #define int long long
        priority_queue <pi, vector<pi>, greater<pi>> pq;  
        int lo = 0, hi = nums.size() - 1, res = 0;
        for (; lo < c; ++lo) {
            pq.push({nums[lo], lo});
        }
        for (int i = 0; i < c and lo < hi; ++i, --hi) {
            pq.push({nums[hi], hi});
        }
        for (int i = 0; i < k; ++i) {
            auto [p1, p2] = pq.top();
            res += p1;
            pq.pop();
            if (p2 < lo and lo <= hi) {        
                pq.push({nums[lo], lo});
                  ++ lo;
            }
            else if (p2 > hi and lo <= hi) {
                pq.push({nums[hi], hi});
                --hi;
            }
        }
        #undef int
        return res;
    }
};
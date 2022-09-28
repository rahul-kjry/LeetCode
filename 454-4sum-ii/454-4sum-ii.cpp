class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        int res = 0;
        unordered_map<int,int> mp;
        for (int & i : nums1) {
            for (int & j : nums2) {
                ++ mp[i + j]; 
            }
        }
        for(int & i : nums3) {
            for(int & j : nums4) {
               if(mp.count(-i-j)) {
                   res += mp[-i-j];
               }
            }
        } 
        return res;
    }
};
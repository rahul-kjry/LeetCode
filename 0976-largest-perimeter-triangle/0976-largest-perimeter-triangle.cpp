class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        for (int i = 0; i < nums.size() - 2; ++i) {
            if (nums[i] < nums[i + 1] + nums[i + 2]) {
                return accumulate(nums.begin() + i, nums.begin() + i + 3, 0);
            } 
        }
        return 0;
    }
};
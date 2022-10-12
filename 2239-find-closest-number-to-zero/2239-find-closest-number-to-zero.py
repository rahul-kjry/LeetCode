class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), [](int & a, int & b){
            return abs(a) < abs(b);
        });
        if (find(nums.begin(), nums.end(), abs(nums[0])) != nums.end()) {
            return abs(nums[0]);
        }
        return nums[0];
    }
};
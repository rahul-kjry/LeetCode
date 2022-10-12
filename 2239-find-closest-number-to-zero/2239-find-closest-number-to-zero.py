class Solution:
    def findClosestNumber(self, nums: List[int]) -> int:
        nums.sort(key = lambda x : abs(x))
        if abs(nums[0]) in nums:
            return abs(nums[0])
        return nums[0]
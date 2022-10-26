class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        sum, pre = 0, 0
        st = set()
        for i in nums:
            sum += i
            if sum % k in st:
                return True
            st.add(pre)
            pre = sum % k
        return False
        
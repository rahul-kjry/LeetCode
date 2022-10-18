class Solution:
    def maxProduct(self, words: List[str]) -> int:
        masks = []
        res = 0
        for word in words:
            mask = 0
            for ch in word:
                mask |= (1 << ord(ch))
            masks.append(mask)
        for i in range(len(masks)):
            for j in range(i + 1, len(masks)):
                if masks[i] & masks[j] == 0:
                    res = max(res, len(words[i]) * len(words[j]))
        return res
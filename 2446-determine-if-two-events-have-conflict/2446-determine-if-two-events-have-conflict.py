class Solution:
    def haveConflict(self, a: List[str], b: List[str]) -> bool:
        def g(s):
            return int(s[:2]) * 60 + int(s[3:])
        a[0] = g(a[0])
        a[1] = g(a[1])
        b[0] = g(b[0])
        b[1] = g(b[1])
        l = max(a[0], b[0])
        r = min(a[1], b[1])
        return l <= r
        
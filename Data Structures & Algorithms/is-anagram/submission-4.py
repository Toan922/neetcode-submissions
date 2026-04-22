class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        count_s = dict(Counter(s))
        count_t = dict(Counter(t))

        if count_s == count_t:
            return True
        return False

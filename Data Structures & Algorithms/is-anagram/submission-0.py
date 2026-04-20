class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False

        dict_s = dict(Counter(s))
        dict_t = dict(Counter(t))

        if dict_s == dict_t:
            return True
        else:
            return False
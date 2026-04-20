class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # if s length != t length def not anagram -> return false
        if len(s) != len(t):
            return False

        # def two dicts representing the count of chars in s and t
        countS = dict(Counter(s))
        countT = dict(Counter(t))

        # if elements in countS == countT then anagram -> return true
        if countS == countT:
            return True
        
        # otherwise return false
        return False
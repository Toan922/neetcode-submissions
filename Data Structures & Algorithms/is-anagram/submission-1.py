class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # This is to just end it early since anagrams are same length
        if len(s) != len(t):
            return False

        # declaring the two empty dictionaries
        count_s = {}
        count_t = {}

        for index in range(len(s)):
            count_s[s[index]] = 1 + count_s.get(s[index], 0)
            count_t[t[index]] = 1 + count_t.get(t[index], 0)
        
        for char in count_s:
            if count_s[char] != count_t.get(char, 0):
                return False

        return True
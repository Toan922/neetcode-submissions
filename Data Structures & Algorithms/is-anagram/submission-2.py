class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        # This is to just end it early since anagrams are same length
        if len(s) != len(t):
            return False

        # declaring the two empty dictionaries
        count_s = {}
        count_t = {}

        # iterate over the string s and increment the count of each char
        for index in range(len(s)):
            # use .get(char, 0) so that if char is not seen prev, set to 0
            count_s[s[index]] = 1 + count_s.get(s[index], 0)
            count_t[t[index]] = 1 + count_t.get(t[index], 0)
        
        # iterate over the s dict
        for char in count_s:
            # compare char in s dict to the one in t dict, if not in return F
            # use .get(char, 0) to prevent any KeyErrors if char not in t dict
            if count_s[char] != count_t.get(char, 0):
                return False

        # return T at the end
        return True
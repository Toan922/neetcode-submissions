class Solution:
    def isPalindrome(self, s: str) -> bool:
        # start off with declaring a str that will store the str s with only alphanumeric characters
        s_al_num = ""

        # declare a left and right pointer
        l, r = 0, len(s) - 1

        # keep looping until l is past r
        while l < r:
            # loop if the character at l is not alphanumeric do the same for character at r
            while l < r and not self.alNum(s[l]):
                # increment l
                l += 1
            while r > l and not self.alNum(s[r]):
                # decrement r
                r -= 1
            
            # check if the two characters match up w/ e/o -> if no match return false
            if s[l].lower() != s[r].lower():
                return False

            # increment l and r
            l, r = l + 1, r - 1

        return True

    
    # need to def a separate function that will return whether a character is alphanumeric
    def alNum(self, c: str) -> bool:
        return (ord('A') <= ord(c) <= ord('Z') or
                ord('a') <= ord(c) <= ord('z') or
                ord('0') <= ord(c) <= ord('9'))
class Solution:
    def isPalindrome(self, s: str) -> bool:
        # def a string representing only the alpha numeric chars in s
        alnums = ""

        # iterate over the string
        for char in s:
            # if char is alpha numeric then add char to alnums
            if char.isalnum():
                alnums += char.lower()

        # return the bool val of alnum compared to its reverse via [::-1]
        return alnums == alnums[::-1]

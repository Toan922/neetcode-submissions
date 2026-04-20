class Solution:
    def isPalindrome(self, s: str) -> bool:
        # def leftPointer as the start of the string
        leftPointer = 0
        # def rightPointer as the end of the string
        rightPointer = len(s) - 1

        # while the left and right pointer have not met, keep looping
        while leftPointer < rightPointer:
            # while char from leftPointer != alpha numeric, increment
            while leftPointer < rightPointer and not self.isAlphaNum(s[leftPointer]):
                leftPointer += 1
            # while char from rightPointer != alpha numeric, decrement
            while rightPointer > leftPointer and not self.isAlphaNum(s[rightPointer]):
                rightPointer -= 1
            
            # if the left and rightPointer vals != then return false
            if s[leftPointer].lower() != s[rightPointer].lower():
                return False

            # increment/decrement left and rightPointers
            leftPointer += 1
            rightPointer -= 1

        #otherwise return true
        return True


    
    '''
    Method: isAlphaNum

    Input: char, representing the current char

    Output: bool, representing if the char was alpha numeric

    Used to determine if the current char is alpha numeric for the
    while loop that will determine whether to increment the left and
    right indices in isPalindrone() 
    '''
    def isAlphaNum(self, char: str) -> bool:
        # check if char falls between uppercase letters
        if ord('A') <= ord(char) <= ord('Z'):
            return True
        # check if char falls between lowercase letters
        elif ord('a') <= ord(char) <= ord('z'):
            return True
        # check if char is a digit
        elif ord('0') <= ord(char) <= ord('9'):
            return True
        # otherwise return false
        else:
            return False
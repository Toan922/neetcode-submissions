class Solution:
    def isValid(self, s: str) -> bool:
        # declare a dict w/ key = close bracket and assoc entry = open
        openClose = {
            '}' : '{',
            ']' : '[',
            ')' : '('
        }

        # declare a stack that keeps track of opened
        openStack = []

        # iterate over str
        for char in s:
            # check if char is a closing bracket
            if char in openClose:
                # check to see if stack is not empty and top of the
                # stack is the associated open bracket
                if openStack and openStack[-1] == openClose[char]:
                    # pop the associated open bracket
                    openStack.pop()
                # if not then improper closing -> return false
                else:
                    return False
            # otherwise append char to stack
            else:
                openStack.append(char)
        
        # return true if stack is empty otherwise return false
        return True if not openStack else False

            
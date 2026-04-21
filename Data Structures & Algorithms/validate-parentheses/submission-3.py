class Solution:
    def isValid(self, s: str) -> bool:
        openClose = {
            ']' : '[',
            '}' : '{',
            ')' : '('
        }

        openStack = []

        for char in s:
            if char in openClose:
                if openStack and openStack[-1] == openClose[char]:
                    openStack.pop()
                else:
                    return False
            else:
                openStack.append(char)

        return True if not openStack else False
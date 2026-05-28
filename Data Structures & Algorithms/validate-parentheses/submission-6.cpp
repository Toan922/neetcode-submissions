class Solution {
public:
    bool isValid(string s) {
        //if the length of str s is odd then there is no way for there to be valid braces
        if(s.length() % 2 == 1)
        {
            return false;
        }

        //declare a map w/ the key being the closing bracket and the value being the open one
        unordered_map<char, char> braces = {
            {'}', '{'},
            {')', '('},
            {']', '['}
        };

        //init a stack that tracks what brackets are open
        stack<char> currOpen;

        //iterate through the string
        for(char c : s)
        {
            //check if the current element is a closing brace
            if(braces.count(c))
            {
                //check if the current top element in the stack is the equivalent open brace
                if(!currOpen.empty() && (currOpen.top() == braces[c]))
                {
                    //if it is the equivalent open brace then pop it
                    currOpen.pop();
                }
                //otherwise the braces are closed in the improper order so return false
                else
                {
                    return false;
                }
            }
            //otherwise the current element is an open brace so add to the stack
            else
            {
                currOpen.push(c);
            }
        }

        //if the full loop went through then stack should be empty -> return whether it is empty or not
        return currOpen.empty();
    }
};

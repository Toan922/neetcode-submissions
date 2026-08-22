class Solution {
public:
    bool isValid(string s) {
        //if str length is odd -> cannot be valid paren
        if(s.length() % 2 == 1) return false;

        //map the closing brace to its assoc opening brace
        unordered_map<char, char> braces = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };

        //keep track of curr opening brace using a stack
        stack<char> openbrace;

        //keep looping through s
        for(char c : s)
        {
            //check to see if the curr char is an opening or closing brace
            if(!braces.count(c)) openbrace.push(c);
            else
            {
                //if the stack is not empty and the top open brace matches -> pop the stack
                if(!openbrace.empty() && (braces[c] == openbrace.top())) openbrace.pop();
                else return false;
            }
        }

        //passed tests -> check to see if the stack is empty
        return openbrace.empty();
    }
};

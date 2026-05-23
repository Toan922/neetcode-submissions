#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        unordered_map<char, char> bracketMap = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };

        stack<char> strStack;

        for (char c : s)
        {
            if (bracketMap.count(c))
            {
                if (!strStack.empty() && strStack.top() == bracketMap[c])
                {
                    strStack.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                strStack.push(c);
            }
        }

        return strStack.empty();
    }
};

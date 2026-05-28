#include <bits/stdc++.h>

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        //create a stack representing the integers that we will be evaluating
        stack<int> digits;

        //iterate through the vector
        for(int i = 0; i < tokens.size(); i++)
        {
            //if the token is not an operator -> it is a digit
            if(tokens[i] != "+" && tokens[i] != "-" && tokens[i] != "/" && tokens[i] != "*")
            {
                //push the int version of the digit
                digits.push(stoi(tokens[i]));
            }
            //otherwise it is an operator
            else
            {
                //if an operator is encountered pop 2 elements off digits stack then operate
                //operand2 is the first pop since it got pushed after operand1
                int operand2 = digits.top();
                digits.pop();
                int operand1 = digits.top();
                digits.pop();
                int result = 0;

                //determine which operator is being performed and compute result
                if(tokens[i] == "+")
                {
                    result = operand1 + operand2;
                }
                else if(tokens[i] == "-")
                {
                    result = operand1 - operand2;
                }
                else if(tokens[i] == "*")
                {
                    result = operand1 * operand2;
                }
                else
                {
                    result = operand1 / operand2;
                }

                //push result back onto the digits stack
                digits.push(result);
            }
        }

        //by the end the only thing remaining in the digits stack should be the final result
        return digits.top();
    }
};

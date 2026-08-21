class Solution {
public:
    bool isPalindrome(string s) {
        //if the size of str s is 1 -> automatically a palindrome
        if (s.size() < 2) return true;

        //init the left and right ptrs where left is the start of the str and right is end
        int left = 0;
        int right = s.size() - 1;

        //iterate until left is over right
        while(left < right)
        {
            //keep iterating left until it reaches an alpha num char
            while(!isAlphaNum(tolower(s[left])) && left < right) left++;
            //keep decrementing right until it reaches an alpha num char
            while(!isAlphaNum(tolower(s[right])) && right > left) right--;

            //compare the two chars
            if(tolower(s[left]) != tolower(s[right])) return false;

            //increment/decrement left and right
            left++;
            right--;
        }

        //if loop finished -> is a palindrome
        return true;
    }

    //creating a function that checks if the curr char is alphaNum lowercased
    bool isAlphaNum(char c)
    {
        if((c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
        {
            return true;
        }
        else return false;
    }
};

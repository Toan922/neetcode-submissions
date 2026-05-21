class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int right = s.length() - 1;

        while(left < right)
        {
            while(left < right && !(isalnum(s.at(left))))
            {
                left++;
            }
            while(right > left && !(isalnum(s.at(right))))
            {
                right--;
            }

            if(tolower(s.at(left)) != tolower(s.at(right)))
            {
                return false;
            }

            left++;
            right--;
        }

        
        return true;
    }
};

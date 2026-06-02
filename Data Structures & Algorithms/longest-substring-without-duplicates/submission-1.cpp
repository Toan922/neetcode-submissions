class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        //init a set that keeps track of all the characters seen thus far in the substring
        unordered_set<char> substr;
        //init a left pointer that will be the start of s
        int left = 0;
        //init a var that will keep track of the longest length seen so far
        int longest = 0;

        //loop through s treating the index as the right most character seen
        for(int right = 0; right < s.size(); right++)
        {
            //while the character at the right index is in the substr -> remove the leftmost char and increment left
            while(substr.count(s[right]))
            {
                //remove the leftmost element
                substr.erase(s[left]);
                //increment left
                left++;
            }

            //add the right element to the substr
            substr.insert(s[right]);

            //calculate the longest length as the max between longest seen so far and curr right - left
            longest = max(longest, right - left + 1);
        }

        //once through the whole string -> return the longest substr seen so far
        return longest;
    }
};

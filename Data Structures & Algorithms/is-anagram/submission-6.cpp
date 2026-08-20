class Solution {
public:
    bool isAnagram(string s, string t) {
        //handle case where s and t are not same length -> cannot be anagrams
        if(s.size() != t.size()) return false;

        //keep a count of the letters in s
        int count[26] = {0};

        //increment the count of each letter in s
        for(char c : s) count[c - 'a']++;
        //go through every letter in t
        for(char c : t)
        {
            //decrement count of letter if t has more of that letter than s -> cannot be an anagram
            if(--count[c - 'a'] < 0)
            {
                //return false
                return false;
            }
        }

        //if tests passed then return true
        return true;
    }
};

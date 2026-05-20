class Solution {
public:
    bool isAnagram(string s, string t) {
        // do basic length check first
        if (s.length() != t.length())
        {
            return false;
        }

        // sort both s and t
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // check if they are equal
        return s == t;
    }
};

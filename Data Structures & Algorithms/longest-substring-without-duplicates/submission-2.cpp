class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int sizeOfString = s.length();
        unordered_set<char> characterSet;
        int left = 0, maximumLength = 0;
        for(int right = 0; right < sizeOfString; right++){
            while(characterSet.count(s[right])){
                characterSet.erase(s[left]);
                left++;
            }
            maximumLength = max(maximumLength, right - left + 1);
            characterSet.insert(s[right]);
        }
        return maximumLength;
    }
};

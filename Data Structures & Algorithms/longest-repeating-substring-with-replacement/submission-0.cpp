class Solution {
public:
    int characterReplacement(string s, int k) {
        //handle when s is of length 1
        if(s.size() == 1) return 1;

        //init a left ptr, and vars that keeps track of the freq of the most freq elem and the longest substr length 
        int left = 0;
        int maxFreq = 0;
        int longest = 0;

        //init a hash map that will keep track of the freq of each character in the window
        unordered_map<char, int> charFreq;

        //loop through each character in s and increment its frequency
        for(int right = 0; right < s.size(); right++)
        {
            //increment the freq of the right char
            charFreq[s[right]]++;

            //take the maxFreq to be the max between the count of the most freq elem seen or the newly seen elem
            maxFreq = max(maxFreq, charFreq[s[right]]);

            //check if the current substring's length - maxFreq > k -> if so increment left
            if((right - left + 1) - maxFreq > k)
            {
                //decrement the freq of the char at left index in the freq map
                charFreq[s[left]]--;
                //increment left
                left++;
            }

            //find the longest substr to be the max of the longest seen so far or curr substr
            longest = max(longest, right - left + 1);
        }

        //return the final size of the window as that will represent the longest possible substring
        return longest;
    }
};

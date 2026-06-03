class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        //handle the case where s1 and s2 are just the same string -> instantly return true
        if(s1 == s2) return true;

        //convert string 1 into a character freq map to compare to
        unordered_map<char, int> s1map;

        //loop through s1 and store its char freqs
        for(const char& c : s1)
        {
            s1map[c]++;
        }

        //init a second char freq map that will keep track of the freq in the substr formed by the window
        unordered_map<char, int> substr;

        //set the window size to be the length of s1 w/ left = start and right = end
        int left = 0;

        //loop through s2 to form the window
        for(int right = 0; right < s2.size(); right++)
        {
            //increment the freq of the right elem
            substr[s2[right]]++;

            //check if the size of the window has exceeded the size of s1 -> if so increment left and change freqs
            if(right - left + 1 > s1.size())
            {
                //decrement the left elem's freq
                substr[s2[left]]--;
                //if that elem hits 0 freq -> erase from the map
                if(substr[s2[left]] == 0) substr.erase(s2[left]);
                //increment left
                left++;
            }

            //check if substr map and the s1map are equal -> if so then that means there is a perm of s1 -> return true
            if(s1map == substr)
            {
                return true;
            }
        }
        
        //assume that once entirety of loops go through -> permutation does not exist -> return false
        return false;
    }
};

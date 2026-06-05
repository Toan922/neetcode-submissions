class Solution {
public:
    string minWindow(string s, string t) {
        //handle the cases where t cannot be in s or s or t are empty
        if(s.empty() || t.empty() || s.size() < t.size()) return "";
        //handle the case where s and t are identical
        if(s == t) return s;

        //init the unordered map that will hold all the unique characters of t
        unordered_map<char, int> tFreq;

        //loop over t to increment the char freq of each char in t
        for(const char& c : t)
        {
            tFreq[c]++;
        }

        //init the left pointer and the length of the string that we will be returning
        int left = 0;
        //set the shortest length str to be int_max for easy checking if there was a substr or not
        int shortest = INT_MAX;
        //set a var that represents what index to start from to form the substr in s that contains t
        int start = 0;

        //create the map that will track the char freq in the window
        unordered_map<char, int> winFreq;
        //init a tracker that tracks the number of characters that are needed to form the substr containing t
        int form = 0;

        //loop over s where the iteration will init the right pointer and form the sliding window
        for(int right = 0; right < s.size(); right++)
        {
            //label the curr elem for easier readability and referencing
            char curr = s[right];
            //increment the occurrence of the curr char
            winFreq[curr]++;

            //check if the curr character is in tFreq and the freq of that curr in window and tFreq are the same
            //perform the count check first since directly accessing a key not in the map will init it to 0
            if(tFreq.count(curr) && winFreq[curr] == tFreq[curr])
            {
                //increment form if the conditions are applicable since all the instances of that char are in winFreq
                form++;
            }

            //keep looping while t is found to be in the window -> shrink the window by bringing left inwards
            while(left <= right && form == tFreq.size())
            {
                //if the minimum length is found to be less than curr window size -> set shortest to be window size and left to be the start index
                if(right -left + 1 < shortest)
                {
                    shortest = right - left + 1;
                    start = left;
                }

                //otherwise decrement the occurence of the left char
                winFreq[s[left]]--;

                //check if the removal of left made the window invalid -> if so then decrement form
                if(tFreq.count(s[left]) && winFreq[s[left]] < tFreq[s[left]]) form--;

                //increment left to bring it inwards
                left++;
            }
        }

        //if the shortest is still INT_MAX -> return an empty str since there is no substr in s that can contain t
        if(shortest == INT_MAX) return "";
        //otherwise return the substr from left all the way to shortest
        return s.substr(start, shortest);
    }
};

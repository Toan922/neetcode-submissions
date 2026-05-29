class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //init a vector of string vectors that we will return
        vector<vector<string>> res;
        //init a map that will group together anagrams based on char count
        unordered_map<string, vector<string>> charCountMap;

        //loop through strs
        for(string s : strs)
        {
            /*
            init a int vector that will keep track of the # of each char's occurence
            make the length 26 (length of the alphabet) and init each position to 0
            */
            vector<int> charCount(26,0);

            //loop through the string and count the occurences of its chars
            for(char c : s)
            {
                //increment that char's occurence count -> calc index by using ascii val - 'a'
                charCount[c - 'a']++;
            }

            //init a key string that will be the charCount vector in a string format
            string key = "";
            //loop through charCount and append the char occurences w/ a delimiter to create a key
            for(int i : charCount)
            {
                //convert i to a string and also append a delimiter character to handle issues w/ double digits
                key += to_string(i) + "#";
            }

            //store the string s into its associated key box in the map
            charCountMap[key].push_back(s);
        }

        //loop through charCountMap using its key val pair and append the val/string vector into res
        for(auto& [key, val] : charCountMap)
        {
            res.push_back(val);
        }

        //return res
        return res;
    }
};

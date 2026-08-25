class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //init the map that will group together the anagram strs
        unordered_map<string, vector<string>> groupedstrs;

        //init the vector that will be returned as the result
        vector<vector<string>> res;

        //loop through all the strs in the vector
        for(string s : strs)
        {
            //init a letter count vector
            vector<int> lettercount(26,0);

            //loop through the chars in the curr str
            for(char c : s)
            {
                //increment the associated letter in lettercount
                lettercount[c - 'a']++;
            }

            //convert lettercount to a str that will be used as a key
            string key = "";
            for(int letter : lettercount)
            {
                //use a delimiter to deal w/ double digit scenario
                key += to_string(letter) + "#";
            }

            //use the str key to append the str to the correct vector
            groupedstrs[key].push_back(s);
        }

        //loop through the associated key val pairs and append to res
        for(auto& [key, val] : groupedstrs)
        {
            res.push_back(val);
        }

        return res;
    }
};

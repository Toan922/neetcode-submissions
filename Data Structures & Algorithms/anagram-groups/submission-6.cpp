class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<string>> anagramMap;
        
        for (string str : strs)
        {
            vector<int> alphabetKey(26,0);

            for (char c : str)
            {
                alphabetKey[c - 'a']++;
            }

            string key = "";

            for (int i = 0; i < 26; i++)
            {
                key += to_string(alphabetKey[i]) + '#';
            }

            anagramMap[key].push_back(str);
        }

        for(auto& [key, value] : anagramMap)
        {
            res.push_back(value);
        }

        return res;
    }
};

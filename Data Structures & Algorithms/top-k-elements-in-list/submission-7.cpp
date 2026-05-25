class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> countMap;
        vector<vector<int>> freq(nums.size() + 1);
        vector<int> res;

        for (int n : nums)
        {
            if (countMap.find(n) != countMap.end())
            {
                countMap[n]++;
            }
            else
            {
                countMap.insert({n, 0});
            }
        }

        for (auto& [key, value] : countMap)
        {
            freq[value].push_back(key);
        }

        for (int i = freq.size() - 1; i > 0; i--)
        {
            for (int j = 0; j < freq[i].size(); j++)
            {
                res.push_back(freq[i][j]);

                if (res.size() == k)
                {
                    return res;
                }
            }
        }
    }
};

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //init the result vector which we will return at the end
        vector<int> result;

        //init the hash map w/ key being the number and val being the freq of said number
        unordered_map<int, int> freqcounter;

        //init the frequency vector which will cluster together numbers with same frequencies in desc order
        //init it to n + 1 to account for the edge case where nums is size 1
        vector<vector<int>> freqvectors(nums.size() + 1);

        //loop through each int n in nums
        for(int n : nums)
        {
            //increment the associated key in freqcounter
            freqcounter[n]++;
        }

        //loop through each key val pair in freqcounter and append key to associated vector in freqvectors
        for(auto& [key, val] : freqcounter)
        {
            freqvectors[val].push_back(key);
        }

        //loop through freqvectors in desc order
        for(int i = freqvectors.size() - 1; i > 0; i--)
        {
            //loop through the vector in freqvectors until k terms have been added to results
            for(int j = 0; j < freqvectors[i].size(); j++)
            {
                result.push_back(freqvectors[i][j]);

                //if k terms have been added -> return result
                if(result.size() == k) return result;
            }
        }

        return {};
    }
};

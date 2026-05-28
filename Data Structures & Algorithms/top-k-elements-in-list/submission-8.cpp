class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        //init a counter hash that will serve as a key
        unordered_map<int, int> counter;
        /*
            init a freq vector which contains vectors
            make the size of nums + 1 to ensure for edge cases where an elem can be the only elem in num
        */
        vector<vector<int>> freq(nums.size() + 1);
        //init the res vector that we need to return
        vector<int> res;

        //loop thru nums and count the number of each elem's occurence
        for(int n : nums)
        {
            //if the elem is already in counter -> increment the count
            if(counter.find(n) != counter.end())
            {
                counter[n]++;
            }
            //otherwise insert the number w/ a count of 0 into counter
            else counter.insert({n, 0});
        }

        //loop through counter grabbing each number and its count as a key value pair
        for(auto& [key, value] : counter)
        {
            //use the value/count as the index for freq and the key/number as what we need to append
            freq[value].push_back(key);
        }

        //iterate backwards through freq
        for(int i = freq.size() - 1; i > 0; i--)
        {
            //for each row of freq keep appending vals to res until res' length == k
            for(int j = 0; j < freq[i].size(); j++)
            {
                res.push_back(freq[i][j]);

                //check if size of res is equal to k -> return res if true
                if(res.size() == k)
                {
                    return res;
                }
            }
        }
    }
};

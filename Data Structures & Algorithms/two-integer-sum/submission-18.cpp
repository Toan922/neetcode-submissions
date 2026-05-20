class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // init the unorderedMap/hash map w/ key being the val and assoc being index
        unordered_map<int, int> hashMap;

        // iterate over the vector nums
        for (int i = 0; i < nums.size(); i++)
        {
            // calc the complement of the target
            int complement = target - nums[i];

            // check if complement is in the map
            auto search = hashMap.find(complement);

            if(search != hashMap.end())
            {
                // return the vector w/ complement index first then current index

                vector<int> v = {search->second, i};

                return v;
            }

            hashMap.insert({nums[i], i});
        }
    }
};

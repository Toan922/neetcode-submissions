class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        //keep track of all seen numbers and their indices using a hash map
        unordered_map<int, int> seen;

        //go through each indice of nums
        for(int i = 0; i < nums.size(); i++)
        {
            //calculate the complement that we need to see
            int complement = target - nums[i];

            //look for complement in hash map
            auto complementSearch = seen.find(complement);

            //if found then return the indices of the complement and the curr num
            if(complementSearch != seen.end())
            {
                return {complementSearch->second, i};
            }

            //otherwise add the curr num and its index to the map
            seen.insert({nums[i], i});
        }
    }
};

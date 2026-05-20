class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        // creating my unordered set/hash set
        unordered_set<int> unorderedSet;

        // interating over nums and incrementing each instance
        for (int i = 0; i < nums.size(); i++)
        {
            if (unorderedSet.find(nums[i]) != unorderedSet.end())
            {
                return true;
            }

            unorderedSet.insert(nums[i]);
        }

        return false;
    }
};
class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        //if nums is size 0 or 1 -> there can be no dupes so return false
        if(nums.size() <= 1) return false;

        //init a map that tracks seen numbers
        unordered_set<int> seen;

        //iterate through nums and check against seen
        for(auto curr : nums)
        {
            //if the curr num is already in the set return true
            if(!seen.insert(curr).second)
            {
                return true;
            }
        }

        //case where nums has passed entirely -> return false
        return false;
    }
};
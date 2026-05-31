class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //handle the empty nums case
        if(nums.empty()) return 0;

        //convert nums into an unordered set
        unordered_set<int> numsSet(nums.begin(), nums.end());
        //init longest to be 1
        int longest = 1;

        //loop through each number in numsSet
        for(int n : numsSet)
        {
            //check if the prev number is in the set
            if(!numsSet.count(n - 1))
            {
                //if not then consider that number as the start of a seq
                //init a length var that is set to 1
                int length = 1;

                //loop until the next number in the seq is not in the set
                while(numsSet.count(n + 1))
                {
                    //increment length
                    length++;
                    //increment the curr num
                    n++;
                }

                //take longest as the max of curr longest and length
                longest = max(length, longest);
            }
        }

        //return longest
        return longest;
    }
};

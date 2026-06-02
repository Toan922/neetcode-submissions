class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        //handle the case where nums is empty
        if(nums.empty()) return 0;

        //convert the vector into a hash set
        unordered_set<int> numsSet(nums.begin(), nums.end());
        //init the var that will keep track of the longest seq seen so far
        int longest = 1;

        //loop over the set
        for(int n : numsSet)
        {
            //check if the number n can be the start of a seq -> only if n - 1 is not in numsSet
            if(numsSet.count(n - 1))
            {
                continue;
            }
            //init a length var that will track the current length of the seq
            int seq = 1;
            //loop continuously while the seq is still valid -> until n + 1 is no longer in numsSet
            while(numsSet.count(n + 1))
            {
                //increment the length of the seq
                seq++;
                //increment n
                n++;
            }

            //set longest to be the max between the curr longest seen and the curr seq length
            longest = max(seq, longest);
        }

        //return the longest seq seen
        return longest;
    }
};
